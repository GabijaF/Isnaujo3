cmake_minimum_required(VERSION 3.27)
project(visas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(visas
        f.cpp
        f.h
        h.cpp
        h.h
        l_1.cpp
        l_2.cpp
        l_3.cpp
        listai.cpp
        main.cpp
        v_1.cpp
        v_2.cpp
        v_3.cpp
        vektorius.cpp
        zmogus.h)

