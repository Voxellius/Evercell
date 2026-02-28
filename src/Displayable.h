#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>

#include "Display.h"

class Displayable {
    public:
        void render(Display display);

    protected:
        void render_commands(Display display, std::wstring left, std::wstring right);
};

#endif