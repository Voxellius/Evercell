#!/bin/bash

./tools/font-generator personalities/evercell/bold-9-latin.font.txt personalities/evercell/build/bold-9-latin.font
./tools/font-embedder font_bold_9_latin personalities/evercell/build/bold-9-latin.font personalities/evercell/build/bold-9-latin.font.h

pushd targets/sdl2
    cmake .
    make
popd