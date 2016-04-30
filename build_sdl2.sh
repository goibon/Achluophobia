#!/bin/sh
hg clone https://hg.libsdl.org/SDL SDL
cd SDL
mkdir build
cd build
../configure
make
sudo make install
cd ../..

wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz
tar -xvf SDL2_ttf-2.0.14.tar.gz
cd SDL2_ttf-2.0.14
mkdir build
cd build
../configure
make
sudo make install
cd ../..

wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.1.tar.gz
tar -xvf SDL2_image-2.0.1.tar.gz
cd SDL2_image-2.0.1
mkdir build
cd build
../configure
make
sudo make install
