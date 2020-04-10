//
// Created by erik on 9/04/20.
//

#ifndef ONLYADDPROJECTC_SDL_UTILS_H
#define ONLYADDPROJECTC_SDL_UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

struct SDL_Package
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    unsigned short* screen_buffer;

    //These will be kept as regular integers instead of fixed point decimals for the sake of convenience
    unsigned int win_width;
    unsigned int win_height;
    unsigned int win_scale;
};

void start_SDL(struct SDL_Package* p);
void update_screen(struct SDL_Package* p);
void end_SDL(struct SDL_Package* p);

#endif //ONLYADDPROJECTC_SDL_UTILS_H
