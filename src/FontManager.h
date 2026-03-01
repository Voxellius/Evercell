#ifndef FONTMANAGER_H_
#define FONTMANAGER_H_

#include <vector>

#include "Font.h"

class FontManager {
    public:
        static FontManager& the();

        Font* load_font_data(uint8_t* font_data, size_t length);
    
    private:
        std::vector<Font> _fonts;
};

#endif