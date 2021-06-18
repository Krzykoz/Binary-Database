#include <iostream>
#include <fstream>
#include <vector>
#include "pch.h"

int main() {
    int vectSize;
    std::vector <int> sizes;
    std::vector <Vehicle *> vehicles;

    Car car("Tesla", "Model S", 2021, 1020.0f, "Sedan", "Solar Red", 5, 3);
    vehicles.push_back(&car);
    Bike bike("Korss", "E-Bike MTB", 2020, 0.3f, 27, "Aluminium");
    vehicles.push_back(&bike);
    Other other("Xiaomi", "Mi Electric Scooter", 2018, 0.05f, 20, 5200);

    car.describe();
    bike.describe();
    other.describe();
    vehicles[0]->describe();
    vehicles[1]->describe();


    std::fstream file;
    file.open("records.dat", std::ios::out | std::ios::binary);

    if(file.is_open()){
        file.write(reinterpret_cast<char*>(vehicles[0]), sizeof(Car));
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