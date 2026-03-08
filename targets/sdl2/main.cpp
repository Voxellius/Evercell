#include <SDL2/SDL.h>
#include <stdio.h>

#include "profile.h"
#include "Display.h"
#include "Colour.h"
#include "FontManager.h"
#include "bold-9-latin.font.h"

#define DISPLAY_SCALE 4

void handle_sdl_error() {
    fprintf(stderr, "SDL2 error: %s\n", SDL_GetError());
    exit(1);
}

void blit_display(SDL_Surface* surface) {
    native_colour_t* data = Display::the().front_buffer->get_data();

    for (int y = 0; y < DISPLAY_HEIGHT; y++) {
        for (int x = 0; x < DISPLAY_WIDTH; x++) {
            size_t index = Display::coords_to_index(x, y);
            native_colour_t pixel = data[index];
            Colour24 pixel24 = pixel.to_24_bit_colour();

            SDL_Rect rect = (SDL_Rect) {
                .x = x * DISPLAY_SCALE,
                .y = y * DISPLAY_SCALE,
                .w = DISPLAY_SCALE,
                .h = DISPLAY_SCALE
            };

            SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, pixel24.red, pixel24.green, pixel24.blue));
        }
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        handle_sdl_error();
    }

    SDL_Window* window = SDL_CreateWindow(
        "Evercell",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        DISPLAY_WIDTH * DISPLAY_SCALE,
        DISPLAY_HEIGHT * DISPLAY_SCALE,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        handle_sdl_error();
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Event event;

    Font* font = FontManager::the().load_font_data(font_bold_9_latin, font_bold_9_latin_len);

    Display::the().back_buffer->draw_text(font, 1, 1, L"ABCDEFGHIJKLMN");
    Display::the().back_buffer->draw_text(font, 1, 11, L"OPQR");
    Display::the().back_buffer->draw_text(font, 1, 21, L"abcdefghijklmnop");
    Display::the().back_buffer->draw_text(font, 1, 31, L"qr");
    Display::the().flip();

    while (true) {
        blit_display(surface);
        SDL_UpdateWindowSurface(window);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyWindow(window);
                SDL_Quit();
    
                return 0;
            }
        }
    }
}