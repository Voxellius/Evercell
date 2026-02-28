#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>

#include "Graphic.h"
#include "Colour.h"

class Display {
    public:
        Display();
        ~Display();

        Graphic<native_colour_t>* back_buffer;
        Graphic<native_colour_t>* front_buffer;

        static Display& the();

        static inline size_t coords_to_index(unsigned int x, unsigned int y) {
            if (x >= DISPLAY_WIDTH || y >= DISPLAY_HEIGHT) {
                return 0;
            }

            return (y * DISPLAY_WIDTH) + x;
        }

        void flip();
};

#endif