#include "Other.h"
#include <iostream>
#include <cstring>

Other::Other() {

}

Other::Other(const char manufacturer[25], const char name[25],
           unsigned year, float power,float range, unsigned battery)
        : Vehicle(manufacturer, name, year, power), _range(range), _battery(battery) {}

void Other::describe() {
    std::cout << this->_manufacturer << " " << this->_name << " " << this->_year <<"\n";
    std::cout << this->_power << " HP, " << "Range: " << this->_range << " KM, Battery capacity: " << this->_battery << " mAh\n\n";
}