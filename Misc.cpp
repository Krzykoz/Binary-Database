#include "Misc.h"
#include <iostream>
#include <cstring>
#include <iomanip>

Misc::Misc() = default;

Misc::~Misc()= default;

Misc::Misc(const Misc& src)
        : Vehicle(src._manufacturer, src._name, src._year, src._power), _range(src._range), _battery(src._battery) {
}

Misc::Misc(const char manufacturer[25], const char name[25],
           unsigned year, float power,float range, unsigned battery)
        : Vehicle(manufacturer, name, year, power), _range(range), _battery(battery) {}

Misc& Misc::operator=(const Misc & src) {
    strcpy(this->_name, src._name);
    strcpy(this->_manufacturer, src._manufacturer);
    this->_power = src._power;
    this->_range = src._range;
    this->_year = src._year;
    this->_battery = src._battery;
    return *this;
}
void Misc::describe() {
    std::cout << std::setw(10) << this->_manufacturer << " | " << std::setw(20) << this->_name << " | "
    <<  std::setw(4) << this->_year << " | " << std::setw(6) << this->_power << " HP | Zasięg:  "
    << std::setw(10) <<this->_range << " | Pojemność Baterii:   " << this->_battery << "\n";
}

int Misc::size() {
    return sizeof(*this);
}

void Misc::setData(){
    const char *manu[25];
    const char *name[25];
    unsigned year;
    float power;
    float range;
    unsigned battery;

    std::cout << "\nPodaj nazwę producenta pojazdu: ";
    std::cin >> (signed char *) manu;
    strcpy(this->_manufacturer, reinterpret_cast<const char *>(manu));

    std::cout << "\nPodaj nazwę pojazdu: ";
    std::cin >> (signed char *) name;
    strcpy(this->_name, reinterpret_cast<const char *>(name));

    std::cout << "\nPodaj rok produkcji pojazdu: ";
    std::cin >> year;
    _year = year;

    std::cout << "\nPodaj moc pojazdu: ";
    std::cin >> power;
    _power = power;

    std::cout << "\nPodaj zasięg pojazdu: ";
    std::cin >> range;
    _range = range;

    std::cout << "\nPodaj pojemność batteri pojazdu: ";
    std::cin >> battery;
    _battery = battery;
}