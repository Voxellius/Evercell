#include <string>

#include "Graphic.h"
#include "Colour.h"

template<class T> Graphic<T>::Graphic(unsigned int width, unsigned int height) {
    _data = new T[width * height];
    _brush = T::grey(0);

    for (int i = 0; i < width * height; i++) {
        _data[i] = T::grey(255);
    }
}

template<class T> Graphic<T>::~Graphic() {
    delete _data;
}

template<class T> void Graphic<T>::draw_pixel(unsigned int x, unsigned int y) {
    if (x > _width || y > _height) {
        return;
    }

    _unsafe_draw_pixel(x, y);
}

template<class T> void Graphic<T>::draw_text(Font* font, unsigned int x, unsigned int y, std::wstring text) {
    for (wchar_t wc : text) {
        Glyph* glyph = font->get_glyph(wc);

        if (glyph->get_bitmap_offset() == -1) {
            continue;
        }

        unsigned int width = glyph->get_width();
        unsigned int height = font->get_size();
        uint8_t* bitmap = font->get_bitmap() + glyph->get_bitmap_offset();
        uint8_t current_bitmap_byte = 0;
        unsigned int i = 0;

        for (unsigned int gy = 0; gy < height; y++) {
            for (unsigned int gx = 0; gx < width; x++) {
                if (i % 8 == 0) {
                    current_bitmap_byte = *bitmap;
                    bitmap++;
                }

                if (current_bitmap_byte & 1) {
                    _unsafe_draw_pixel(gx + x, gy + y);
                }

                current_bitmap_byte >>= 1;
                i++;
            }
        }

        x += width;
        x++; // Add 1 pixel of kerning
    }
}

template class Graphic<native_colour_t>;