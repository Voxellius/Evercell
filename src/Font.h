#ifndef FONT_H_
#define FONT_H_

#include <cstdint>
#include <string>

enum FontStyle {
    PLAIN       = 0,
    BOLD        = 1,
    ITALIC      = 2,
    UNDERLINE   = 4
};

class Glyph {
    public:
        uint8_t get_width() {return _width;}
        uint16_t* get_bitmap_offset() {return _bitmap_offset;}

    private:
        uint8_t _width;
        uint16_t* _bitmap_offset;
};

class FontPage {
    public:
        Glyph* get_glyph(uint8_t c);

    private:
        Glyph _glyphs[256];
};

class Font {
    public:
        Font(unsigned int size, FontStyle style);

        unsigned int get_size() {return _size;}
        FontStyle get_style() {return _style;}
        uint8_t* get_bitmap() {return _bitmap;}

        Glyph* get_glyph(wchar_t wc);
        unsigned int compute_text_width(std::wstring text);

    private:
        unsigned int _size;
        FontStyle _style;

        uint8_t* _bitmap;
        FontPage* _font_pages[256];
};

#endif