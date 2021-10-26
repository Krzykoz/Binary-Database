cmake_minimum_required(VERSION 3.19)
project(Database)

set(CMAKE_CXX_STANDARD 14)

add_executable(Database main.cpp Vehicle.cpp Vehicle.h Car.cpp Car.h Bike.cpp Bike.h Misc.cpp Misc.h pch.h Database.cpp Database.h)