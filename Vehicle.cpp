#include "Vehicle.h"
#include <cstring>

Vehicle::Vehicle() {

}

Vehicle::Vehicle(const char manufacturer[25], const char name[25], unsigned year, float power)
    : _year(year), _power(power) {
    strcpy(_manufacturer, manufacturer);
    strcpy(_name, name);
}