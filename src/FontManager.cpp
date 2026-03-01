#include "FontManager.h"

FontManager& FontManager::the() {
    static FontManager instance;

    return instance;
}

Font* FontManager::load_font_data(uint8_t* font_data, size_t length) {
    size_t i = 0;

    unsigned int size = font_data[i++];
    FontStyle style = (FontStyle)font_data[i++];
    Font font(size, style, font_data);

    _fonts.push_back(font);

    Font* font_ptr = &font;

    while (i < length) {
        wchar_t wc = (font_data[i++] << 8) | font_data[i++];
        uint8_t width = font_data[i++];
        Glyph glyph(width, i);

        font_ptr->set_glyph(wc, glyph);

        std::div_t div_result = std::div(width * size, 8);

        i += div_result.quot + !!div_result.rem;
    }

    return font_ptr;
}