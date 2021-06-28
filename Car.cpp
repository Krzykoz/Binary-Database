#include "Car.h"
#include <iostream>
#include <cstring>

Car::Car() = default;

Car::Car(const Car& src)
    : Vehicle(src._manufacturer, src._name, src._year, src._power), _seats(src._seats), _motors(src._motors) {
    strcpy(_body, src._body);
    strcpy(_color, src._color);
}

Car::Car(const char manufacturer[25], const char name[25],
         unsigned year, float power,const char body[25],
         const char color[25], unsigned seats, unsigned motors)
    : Vehicle(manufacturer, name, year, power), _seats(seats), _motors(motors) {
    strcpy(_body, body);
    strcpy(_color, color);
}

Car& Car::operator=(const Car & src) {
    strcpy(this->_body, src._body);
    strcpy(this->_color, src._color);
    strcpy(this->_name, src._name);
    strcpy(this->_manufacturer, src._manufacturer);
    this->_seats = src._seats;
    this->_motors = src._motors;
    this->_year = src._year;
    return *this;
}

void Car::describe() {
    std::cout << this->_manufacturer << " " << this->_name << " " << this->_year <<"\n";
    std::cout << this->_power << " HP, " << "Body type: " << this->_body << ", Color: " << this->_color << ", Seats: " << this->_seats << ", Motors: " << this->_motors << "\n\n";
}

int Car::size() {
    return sizeof(*this);
}