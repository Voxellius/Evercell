#include "FontPage.h"

Glyph* FontPage::get_glyph(uint8_t c) {
    return &_glyphs[c];
}