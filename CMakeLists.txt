cmake_minimum_required(VERSION 2.6)
project(Achluophobia)

# List source files
include_directories(include)
set(SOURCE_FILES src/main.cpp
                 src/lamp.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Achluophobia ${SOURCE_FILES})
target_link_libraries(Achluophobia ${SDL2_LIBRARY})
