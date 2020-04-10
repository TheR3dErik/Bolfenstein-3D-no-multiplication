//
// Created by erik on 9/04/20.
//

#ifndef ONLYADDPROJECTC_MATH_UTILS_H
#define ONLYADDPROJECTC_MATH_UTILS_H

void print_fixed_digit(unsigned short num, int fixed_point_digits);
unsigned short flip_if_neg(unsigned short num);
unsigned short mul_ints(unsigned short a, unsigned short b, int fixed_point_digits);
unsigned short div_ints(unsigned short a, unsigned short b, int fixed_point_digits);
int num_digits(unsigned short num);
unsigned short negate(unsigned short num);

#endif //ONLYADDPROJECTC_MATH_UTILS_H
