cmake_minimum_required(VERSION 3.31)
project(semigraphics)

set(CMAKE_CXX_STANDARD 23)

add_executable(semigraphics
        main.cpp
        crtbind.cpp
        window.cpp
        semigraphics.cpp
)
