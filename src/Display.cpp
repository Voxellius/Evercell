#include "Display.h"
#include "profile.h"

Display::Display() {
    back_buffer = new Colour[DISPLAY_WIDTH * DISPLAY_HEIGHT];
    front_buffer = new Colour[DISPLAY_WIDTH * DISPLAY_HEIGHT];

    for (int i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT; i++) {
        back_buffer[i] = Colour::grey(0);
        front_buffer[i] = Colour::grey(0);
    }
}

Display::~Display() {
    delete back_buffer, front_buffer;
}

Display& Display::the() {
    static Display instance;

    return instance;
}

void Display::flip() {
    Colour* temp_buffer = back_buffer;

    back_buffer = front_buffer;
    front_buffer = temp_buffer;
}