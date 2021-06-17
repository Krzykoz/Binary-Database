#ifndef PROJEKT_PK_OTHER_H
#define PROJEKT_PK_OTHER_H
#include "Vehicle.h"

class Other : public Vehicle {
public:
    Other();
    Other(const char manufacturer[25], const char name[25],
         unsigned year, float power, float range, unsigned battery);
    void describe() override;
private:
    float _range;
    unsigned _battery;
};


#endif //PROJEKT_PK_OTHER_H
