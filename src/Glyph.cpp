#include "Glyph.h"

Glyph::Glyph() :
_width(0), _bitmap_offset(-1) {}

Glyph::Glyph(uint8_t width, uint16_t bitmap_offset) {
    _width = width;
    _bitmap_offset = bitmap_offset;
}