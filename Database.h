//
// Created by Krzysztof Koźlik on 10/07/2021.
//

#ifndef PROJEKT_PK_DATABASE_H
#define PROJEKT_PK_DATABASE_H


#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Misc.h"


class Database {
public:
    void print();
    int read();
    int save();
    int add();
    int del();
    int menu();
private:
    std::vector <Vehicle *> _vehicles;
};


#endif //PROJEKT_PK_DATABASE_H
