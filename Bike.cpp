#include "Bike.h"
#include <iostream>
#include <cstring>

Bike::Bike() {

}

Bike::Bike(const char manufacturer[25], const char name[25],
         unsigned year, float power,unsigned size, const char frame[25])
        : Vehicle(manufacturer, name, year, power), _size(size) {
    strcpy(_frame, frame);
}

void Bike::describe() {
    std::cout << this->_manufacturer << " " << this->_name << " " << this->_year <<"\n";
    std::cout << this->_power << " HP, " << "Size: " << this->_size << ", Frame material: " << this->_frame << "\n\n";
}