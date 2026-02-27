#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>

class Display {
    public:
        Display();

        char* back_buffer;
        char* front_buffer;

        void flip();
};

#endif