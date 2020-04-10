//
// Created by erik on 9/04/20.
//

#include "sdl_utils.h"

void start_SDL(struct SDL_Package* p)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    atexit(SDL_Quit);

    p->window = SDL_CreateWindow
            (
                    "Bolfenstein 3D",
                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                    p->win_width*p->win_scale, p->win_height*p->win_scale,
                    SDL_WINDOW_SHOWN
            );

    p->renderer = SDL_CreateRenderer
            (
                    p->window,
                    -1,
                    SDL_RENDERER_ACCELERATED
            );

    p->texture = SDL_CreateTexture
            (
                    p->renderer,
                    SDL_PIXELFORMAT_BGR565, //only reason I'm subjecting myself to this is because the calculator does it
                    SDL_TEXTUREACCESS_STREAMING,
                    p->win_width,
                    p->win_height
            );

    SDL_RendererInfo info;
    SDL_GetRendererInfo(p->renderer, &info );
    printf("Renderer name: %s\n", info.name);
    printf("Texture formats:\n");
    for( Uint32 i = 0; i < info.num_texture_formats; i++ )
    {
        printf("%s\n",SDL_GetPixelFormatName( info.texture_formats[i] ));
    }

    p->screen_buffer = malloc(p->win_width * p->win_height * sizeof(unsigned short));

}

void update_screen(struct SDL_Package* p)
{
    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //SDL_RenderClear(renderer);

    SDL_UpdateTexture(p->texture, NULL, p->screen_buffer, p->win_width * sizeof(unsigned short));
    SDL_RenderCopy(p->renderer, p->texture, NULL, NULL);
    SDL_RenderPresent(p->renderer);
}

void end_SDL(struct SDL_Package* p)
{
    SDL_DestroyRenderer(p->renderer);
    SDL_DestroyWindow(p->window);
    SDL_DestroyTexture(p->texture);
    free(p->screen_buffer);
    SDL_Quit();
}
