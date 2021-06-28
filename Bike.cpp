#include "Bike.h"
#include <iostream>
#include <cstring>

Bike::Bike() = default;

Bike::Bike(const char manufacturer[25], const char name[25],
         unsigned year, float power,unsigned size, const char frame[25])
        : Vehicle(manufacturer, name, year, power), _size(size) {
    strcpy(_frame, frame);
}

void Bike::describe() {
    std::cout << this->_manufacturer << " " << this->_name << " " << this->_year <<"\n";
    std::cout << this->_power << " HP, " << "Size: " << this->_size << ", Frame material: " << this->_frame << "\n\n";
}

int Bike::size() {
    return sizeof(*this);
}

void Bike::setData(){
    const char *manu[25];
    const char *name[25];
    unsigned year;
    float power;
    unsigned size;
    const char *frame[25];

    std::cout << "\nPodaj nazwę producenta roweru: ";
    std::cin >> (signed char *) manu;
    strcpy(this->_manufacturer, reinterpret_cast<const char *>(manu));

    std::cout << "\nPodaj nazwę roweru: ";
    std::cin >> (signed char *) name;
    strcpy(this->_name, reinterpret_cast<const char *>(name));

    std::cout << "\nPodaj rok produkcji roweru: ";
    std::cin >> year;
    _year = year;

    std::cout << "\nPodaj moc roweru: ";
    std::cin >> power;
    _power = power;

    std::cout << "\nPodaj rozmiar ramy roweru: ";
    std::cin >> size;
    _size = size;

    std::cout << "\nPodaj materiał ramy roweru: ";
    std::cin >> (signed char *) frame;
    strcpy(this->_frame, reinterpret_cast<const char *>(frame));
}