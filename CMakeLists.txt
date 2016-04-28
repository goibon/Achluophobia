cmake_minimum_required(VERSION 2.6)
project(Achluophobia)

#Fonts
configure_file(fonts/lazy.ttf fonts/lazy.ttf COPYONLY)

# List source files
include_directories(include)
set(SOURCE_FILES src/main.cpp
                 src/lamp.cpp
                 src/texture.cpp
                 src/fontTexture.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR})

add_executable(Achluophobia ${SOURCE_FILES})
target_link_libraries(Achluophobia ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})
