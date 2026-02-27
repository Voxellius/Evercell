#include <SDL2/SDL.h>
#include <stdio.h>

#include "profile.h"

#define DISPLAY_SCALE 4

void handle_sdl_error() {
    fprintf(stderr, "SDL2 error: %s\n", SDL_GetError());
    exit(1);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        handle_sdl_error();
    }

    SDL_Window* window = SDL_CreateWindow(
        "Evercell",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        PROFILE_DISPLAY_WIDTH * DISPLAY_SCALE,
        PROFILE_DISPLAY_HEIGHT * DISPLAY_SCALE,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        handle_sdl_error();
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Event event;

    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyWindow(window);
                SDL_Quit();
    
                return 0;
            }
        }
    }
}