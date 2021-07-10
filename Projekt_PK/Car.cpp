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
    this->_power = src._power;
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

void Car::setData(){
    const char *manu[25];
    const char *name[25];
    unsigned year;
    float power;
    const char *body[25];
    const char *color[25];
    unsigned seats;
    unsigned motors;



    std::cout << "\nPodaj nazwę producenta samochodu: ";
    std::cin >> (signed char *) manu;
    strcpy(this->_manufacturer, reinterpret_cast<const char *>(manu));

    std::cout << "\nPodaj nazwę samochodu: ";
    std::cin >> (signed char *) name;
    strcpy(this->_name, reinterpret_cast<const char *>(name));

    std::cout << "\nPodaj rok produkcji samochodu: ";
    std::cin >> year;
    _year = year;

    std::cout << "\nPodaj moc samochodu: ";
    std::cin >> power;
    _power = power;

    std::cout << "\nPodaj rodzaj nadowzia samochodu: ";
    std::cin >> (signed char *) body;
    strcpy(this->_body, reinterpret_cast<const char *>(body));

    std::cout << "\nPodaj kolor karoseri samochodu: ";
    std::cin >> (signed char *) color;
    strcpy(this->_color, reinterpret_cast<const char *>(color));

    std::cout << "\nPodaj ilość miejsc w samochodzie: ";
    std::cin >> seats;
    _year = seats;

    std::cout << "\nPodaj ilość silników w samochodzie: ";
    std::cin >> motors;
    _year = motors;
}