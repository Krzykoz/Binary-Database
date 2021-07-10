#ifndef PROJEKT_PK_MISC_H
#define PROJEKT_PK_MISC_H
#include "Vehicle.h"

class Misc : public Vehicle {
public:
    Misc();
    Misc(const Misc&);
    Misc(const char manufacturer[25], const char name[25],
         unsigned year, float power, float range, unsigned battery);
    Misc& operator=(const Misc&);
    void describe() override;
    int size() override;
    void setData() override;
private:
    float _range;
    unsigned _battery;
};


#endif //PROJEKT_PK_MISC_H
