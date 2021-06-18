#include <iostream>
#include <fstream>
#include "pch.h"

int main() {
    Car* car = new Car("Tesla", "Model S", 2021, 1020.0f, "Sedan", "Solar Red", 5, 3);

    Bike* bike = new Bike("Korss", "E-Bike MTB", 2020, 0.3f, 27, "Aluminium");

    Other* other = new Other("Xiaomi", "Mi Electric Scooter", 2018, 0.05f, 20, 5200);

    car->describe();
    bike->describe();
    other->describe();

    std::fstream file;
    file.open("records.dat", std::ios::out | std::ios::binary);

    if(file.is_open()){
        file.write(reinterpret_cast<char*>(&car), sizeof(Car));
        file.close();
    }else{
        std::cout << "ERROR!";
    }

   std::cout << "\n" << sizeof(Car) << "\n";

   Car read;

   file.open("records.dat", std::ios::in | std::ios::binary);

    if(file.is_open()){
        file.read(reinterpret_cast<char*>(&read), sizeof(Car));
        file.close();
    }else{
        std::cout << "ERROR!";
    }

    read.describe();

    return 0;
}