#ifndef PROJEKT_PK_VEHICLE_H
#define PROJEKT_PK_VEHICLE_H
#include "Vehicle.h"

class Vehicle {
public:
    Vehicle();
    Vehicle(const char[25], const char[25], unsigned, float);
    virtual void describe() = 0;
    virtual int size() = 0;
    virtual void setData() = 0;
protected:
    char _manufacturer[25];
    char _name[25];
    unsigned _year;
    float _power;
};

#endif //PROJEKT_PK_VEHICLE_H