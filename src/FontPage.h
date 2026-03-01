#ifndef FONTPAGE_H_
#define FONTPAGE_H_

#include "Glyph.h"

class FontPage {
    public:
        Glyph* get_glyph(uint8_t c);

    private:
        Glyph _glyphs[256];
};

#endif