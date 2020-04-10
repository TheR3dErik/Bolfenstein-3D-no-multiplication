//
// Created by erik on 9/04/20.
//

#include "math_utils.h"

#include <stdio.h>
#include <math.h>

void print_fixed_digit(unsigned short num, int fixed_point_digits)
{
    double d = num;
    printf("%.12f\n",d/pow(2,fixed_point_digits));
}

// trying to avoid if statements as much as possible because I don't trust any branching on the z80
unsigned short flip_if_neg(unsigned short num)
{
    unsigned short leading = (num>>15);
    unsigned short xorinator = 0-leading;
    return (num^xorinator) + leading;
}

// function for multiplying unsigned integers because z80 doesn't have a native multiply instruction
unsigned short mul_ints(unsigned short a, unsigned short b, int fixed_point_digits)
{
    unsigned short neg = (a>>15) ^ (b>>15); // checks leading bits of both a and b to determine if they are negative.
    a = flip_if_neg(a);
    b = flip_if_neg(b);

    unsigned int result = 0;
    for (int i = 0; i < 16; i++)
    {
        unsigned int temp = 0;
        temp -= (a >> i) & 1;
        temp &= (b<<i); //basically a really roundabout way of avoiding if statements for efficiency
        result += temp;
    }
    unsigned short xorinator = 0-neg;
    return (unsigned short)((result >> fixed_point_digits)^xorinator) + neg;
}

int num_digits(unsigned short num)
{
    int dig = 16;
    while (!((1 << 15) & num))
    {
        num = num << 1;
        dig--;
    }
    return dig;
}

// function for dividing unsigned integers because z80 doesn't have a native divide instruction
unsigned short div_ints(unsigned short a, unsigned short b, int fixed_point_digits)
{
    unsigned short neg = (a>>15) ^ (b>>15); // checks leading bits of both a and b to determine if they are negative.
    a = flip_if_neg(a);
    b = flip_if_neg(b);

    unsigned short result = 0;
    unsigned short remainder = a;
    int ndigits = num_digits(b);
    b <<= 16-ndigits;
    for (int i = 0; i < 16; i++)
    {
        if (remainder >= b)
        {
            remainder -= b;
            result += (1 << (fixed_point_digits+16-ndigits-i));
        }
        b >>= 1;
    }

    unsigned short xorinator = 0-neg;
    return (result^xorinator) + neg;
}

unsigned short negate(unsigned short num)
{
    return (~num) + 1;
}
