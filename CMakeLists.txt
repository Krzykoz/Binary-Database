cmake_minimum_required(VERSION 3.19)
project(Projekt_PK)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt_PK main.cpp Vehicle.cpp Vehicle.h Car.cpp Car.h Bike.cpp Bike.h Other.cpp Other.h pch.h)