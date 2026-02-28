#include "Display.h"
#include "profile.h"

Display::Display() {
    back_buffer = new Graphic<native_colour_t>(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    front_buffer = new Graphic<native_colour_t>(DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

Display::~Display() {
    delete back_buffer, front_buffer;
}

Display& Display::the() {
    static Display instance;

    return instance;
}

void Display::flip() {
    Graphic<native_colour_t>* temp_buffer = back_buffer;

    back_buffer = front_buffer;
    front_buffer = temp_buffer;
}