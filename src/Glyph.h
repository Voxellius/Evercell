#ifndef GLYPH_H_
#define GLYPH_H_

#include <cstdint>

class Glyph {
    public:
        Glyph();
        Glyph(uint8_t width, uint16_t bitmap_offset);

        uint8_t get_width() {return _width;}
        uint16_t get_bitmap_offset() {return _bitmap_offset;}

    private:
        uint8_t _width;
        uint16_t _bitmap_offset;
};

#endif