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

template<class T> void Graphic<T>::draw_text(Font* font, unsigned int x, unsigned int y, std::wstring text) {
    // TODO: Implement font rendering
}

template class Graphic<native_colour_t>;