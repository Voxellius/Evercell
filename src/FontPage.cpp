#include "FontPage.h"

FontPage::FontPage() {
    for (unsigned int i = 0; i < 256; i++) {
        _glyphs[i] = Glyph(0, -1);
    }
}

Glyph* FontPage::get_glyph(uint8_t c) {
    return &_glyphs[c];
}

void FontPage::set_glyph(uint8_t c, Glyph& glyph) {
    _glyphs[c] = glyph;
}