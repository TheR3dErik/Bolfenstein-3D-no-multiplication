#include <stdio.h>
#include <malloc.h>

#include "math_utils.h"
#include "sdl_utils.h"

/*
 * This exercise is rather pointless in C given that on any CPU made in this millennium, there is support
 * for multiplication and division even with floating point numbers. However, this is not the case for Texas
 * Instruments. Their monopolistic stranglehold on the education market has resulted in an astonishing lack
 * of innovation in their graphing calculators, whose prices have not decreased at all over the past few
 * decades.
 *
 * Fortunately, since their CPUs are so simplistic, this is a great opportunity for me to learn how to program
 * them in assembly as the assembly languages used by modern processors are far too complicated. However, before
 * I jump straight into assembly, I am attempting to program these basic routines in C, because if I can't
 * even do that, then I am hopeless for assembly.
 */


int main()
{
    //print_fixed_digit(mul_ints(5 << 9, 4 << 10, 10),10);

    struct SDL_Package p;
    p.win_width = 320;
    p.win_height = 240;
    p.win_scale = 6;

    start_SDL(&p);

    p.screen_buffer[100*p.win_height + 100] = 0xFFE0; //sets pixel to cyan color on screen

    char running = 1;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
            {
                running = 0;
                break;
            }
        }

        update_screen(&p);
    }

    end_SDL(&p);

    return 0;
}
