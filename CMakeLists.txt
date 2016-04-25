cmake_minimum_required(VERSION 2.6)
project(Achluophobia)

# List source files
set(SOURCE_FILES main.cpp
                 lamp.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lsdl2")
add_executable(Achluophobia ${SOURCE_FILES})
