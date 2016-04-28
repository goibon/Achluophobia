#!/bin/sh
hg clone https://hg.libsdl.org/SDL SDL
cd SDL
mkdir build
cd build
../configure
make
sudo make install
cd ../..

hg clone https://hg.libsdl.org/SDL_ttf/ SDL_ttf
cd SDL_ttf
mkdir build
cd build
../configure
make
sudo make install
cd ../..

hg clone https://hg.libsdl.org/SDL_image/ SDL_image
cd SDL_image
mkdir build
cd build
../configure
make
sudo make install
