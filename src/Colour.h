#ifndef COLOUR_H_
#define COLOUR_H_

#include "profile.h"

struct Colour24 {
    int red : 8;
    int green : 8;
    int blue : 8;
};

struct Colour16 {
    int red : 4;
    int green : 4;
    int blue : 4;

    inline Colour24 to_24_bit_colour() {
        return (Colour24) {
            .red = red << 4,
            .green = green << 4,
            .blue = blue << 4
        };
    }

    static inline Colour16 grey(unsigned char level) {
        return (Colour16) {
            .red = level >> 4,
            .green = level >> 4,
            .blue = level >> 4
        };
    }
};

#if DISPLAY_BPP == 12
    typedef Colour16 native_colour_t;
#endif

#endif