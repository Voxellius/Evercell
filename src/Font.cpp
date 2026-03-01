#include "Font.h"

Font::Font(unsigned int size, FontStyle style) {
    _size = size;
    _style = style;

    _bitmap = nullptr;

    for (unsigned int i = 0; i < 256; i++) {
        _font_pages[i] = nullptr;
    }
}

Glyph* Font::get_glyph(wchar_t wc) {
    FontPage* page = _font_pages[wc >> 8];

    if (!page) {
        static Glyph* unknown = new Glyph(0, -1);

        return unknown;
    }

    return page->get_glyph(wc & 0xFF);
}

unsigned int Font::compute_text_width(std::wstring text) {
    unsigned int width = 0;

    for (wchar_t wc : text) {
        Glyph* glyph = get_glyph(wc);

        if (glyph->get_bitmap_offset() == -1) {
            continue;
        }

        width += glyph->get_width();
        width++; // Add 1 pixel of kerning
    }

    width--; // Remove extra kerned pixel at end

    return width;
}