//
// Created by Krzykoz on 17.06.2021.
//

#ifndef PROJEKT_PK_BIKE_H
#define PROJEKT_PK_BIKE_H
#include "Vehicle.h"

class Bike : public Vehicle {
public:
    Bike();
    Bike(const char manufacturer[25], const char name[25],
        unsigned year, float power, unsigned size, const char frame[25]);
    void describe() override;
private:
    unsigned _size;
    char _frame[25];
};


#endif //PROJEKT_PK_BIKE_H
