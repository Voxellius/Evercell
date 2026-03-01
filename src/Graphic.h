#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include "Font.h"

template<class T> class Graphic {
    public:
        Graphic(unsigned int width, unsigned int height);
        ~Graphic();

        unsigned int get_width() {return _width;}
        unsigned int get_height() {return _height;}
        T* get_data() {return _data;}
        void set_brush(T brush) {_brush = brush;}

        void draw_pixel(unsigned int x, unsigned int y);
        void draw_text(Font* font, unsigned int x, unsigned int y, std::wstring text);

    private:
        unsigned int _width;
        unsigned int _height;
        T* _data;
        T _brush;

        inline void _unsafe_draw_pixel(unsigned int x, unsigned int y) {
            _data[(y * _width) + x] = _brush;
        }
};

#endif