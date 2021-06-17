#include <iostream>
#include "pch.h"

int main() {
    Car* car = new Car("Tesla", "Model S", 2021, 1020.0f, "Sedan", "Solar Red", 5, 3);

    Bike* bike = new Bike("Korss", "E-Bike MTB", 2020, 0.3f, 27, "Aluminium");

    Other* other = new Other("Xiaomi", "Mi Electric Scooter", 2018, 0.05f, 20, 5200);

    car->describe();
    bike->describe();
    other->describe();
    return 0;
}