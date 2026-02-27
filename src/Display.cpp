#include "Display.h"
#include "profile.h"

Display::Display() {
    const size_t buffer_size = PROFILE_DISPLAY_WIDTH * PROFILE_DISPLAY_HEIGHT * PROFILE_DISPLAY_BPP / 8;

    back_buffer = new char[buffer_size];
    front_buffer = new char[buffer_size];
}

void Display::flip() {
    char* temp_buffer = back_buffer;

    back_buffer = front_buffer;
    front_buffer = temp_buffer;
}