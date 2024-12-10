cmake_minimum_required(VERSION 3.28)
project(lab__3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab__3 main.cpp
        book.h
        book.cpp
        category.h
        category.cpp
        library.h
        library.cpp
        BookStorage.h
        BookStorage.cpp)
