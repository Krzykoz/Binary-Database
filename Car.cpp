#include "Car.h"
#include <iostream>
#include <cstring>

Car::Car() = default;

Car::Car(const char manufacturer[25], const char name[25],
         unsigned year, float power,const char body[25],
         const char color[25], unsigned seats, unsigned motors)
    : Vehicle(manufacturer, name, year, power), _seats(seats), _motors(motors) {
    strcpy(_body, body);
    strcpy(_color, color);
}

void Car::describe() {
    std::cout << this->_manufacturer << " " << this->_name << " " << this->_year <<"\n";
    std::cout << this->_power << " HP, " << "Body type: " << this->_body << ", Color: " << this->_color << ", Seats: " << this->_seats << ", Motors: " << this->_motors << "\n\n";
}

int Car::size() {
    return sizeof(*this);
}