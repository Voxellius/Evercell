#ifndef FONTPAGE_H_
#define FONTPAGE_H_

#include "Glyph.h"

class FontPage {
    public:
        FontPage();

        Glyph* get_glyph(uint8_t c);
        void set_glyph(uint8_t c, Glyph& glyph);

    private:
        Glyph _glyphs[256];
};

#endif