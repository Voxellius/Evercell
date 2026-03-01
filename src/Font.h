#ifndef FONT_H_
#define FONT_H_

#include <string>

#include "FontPage.h"
#include "Glyph.h"

enum FontStyle {
    PLAIN       = 0,
    BOLD        = 1,
    ITALIC      = 2,
    BOLD_ITALIC = 4
};

class Font {
    public:
        Font(unsigned int size, FontStyle style, uint8_t* bitmap);

        unsigned int get_size() {return _size;}
        FontStyle get_style() {return _style;}
        uint8_t* get_bitmap() {return _bitmap;}

        Glyph* get_glyph(wchar_t wc);
        void set_glyph(wchar_t wc, Glyph& glyph);
        unsigned int compute_text_width(std::wstring text);

    private:
        unsigned int _size;
        FontStyle _style;
        uint8_t* _bitmap;

        FontPage* _font_pages[256];
};

#endif