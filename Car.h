#ifndef PROJEKT_PK_CAR_H
#define PROJEKT_PK_CAR_H

#include <vector>
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    ~Car() override;
    Car(const Car&);
    Car(const char manufacturer[25], const char name[25],
        unsigned year, float power, const char body[25], const char color[25],
        unsigned _seats, unsigned motors);
    Car& operator=(const Car&);
    void describe() override;
    int size() override;
    void setData() override;
private:
    char _body[25];
    char _color[25];
    unsigned _seats;
    unsigned _motors;
};


#endif //PROJEKT_PK_CAR_H
