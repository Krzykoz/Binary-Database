#include "Other.h"
#include <iostream>
#include <cstring>

Other::Other() = default;

Other::Other(const char manufacturer[25], const char name[25],
           unsigned year, float power,float range, unsigned battery)
        : Vehicle(manufacturer, name, year, power), _range(range), _battery(battery) {}

void Other::describe() {
    std::cout << this->_manufacturer << " " << this->_name << " " << this->_year <<"\n";
    std::cout << this->_power << " HP, " << "Range: " << this->_range << " KM, Battery capacity: " << this->_battery << " mAh\n\n";
}

int Other::size() {
    return sizeof(*this);
}

void Other::setData(){
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