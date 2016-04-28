cmake_minimum_required(VERSION 2.6)
project(Achluophobia)

# List source files
include_directories(include)
set(SOURCE_FILES src/main.cpp
                 src/lamp.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lsdl2")
add_executable(Achluophobia ${SOURCE_FILES})
