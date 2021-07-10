#include "Bike.h"
#include <iostream>
#include <cstring>
#include <iomanip>

Bike::Bike() = default;

Bike::~Bike()= default;

Bike::Bike(const Bike& src)
        : Vehicle(src._manufacturer, src._name, src._year, src._power), _size(src._size) {
    strcpy(_frame, src._frame);
}

Bike::Bike(const char manufacturer[25], const char name[25],
         unsigned year, float power,unsigned size, const char frame[25])
        : Vehicle(manufacturer, name, year, power), _size(size) {
    strcpy(_frame, frame);
}

Bike& Bike::operator=(const Bike & src) {
    strcpy(this->_frame, src._frame);
    strcpy(this->_name, src._name);
    strcpy(this->_manufacturer, src._manufacturer);
    this->_size = src._size;
    this->_power = src._power;
    this->_year = src._year;
    return *this;
}

void Bike::describe() {
    std::cout << std::setw(10) << this->_manufacturer << " | " << std::setw(20) << this->_name << " | "
              <<  std::setw(4) << this->_year << " | " << std::setw(6) << this->_power << " HP | Rozmiar: "
              << std::setw(10) <<this->_size << " | Materiał Ramy:   " << this->_frame << "\n";
}

int Bike::size() {
    return sizeof(*this);
}

int Bike::setData(){
    const char *manu[25];
    const char *name[25];
    unsigned year;
    float power;
    unsigned size;
    const char *frame[25];

    std::cout << "\nPodaj nazwę producenta roweru: ";
    std::cin.getline((char *) manu, 25);
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj nazwę roweru: ";
    std::cin.getline((char *) name, 25);
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj rok produkcji roweru: ";
    std::cin >> year;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj moc roweru: ";
    std::cin >> power;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj rozmiar ramy roweru: ";
    std::cin >> size;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj materiał ramy roweru: ";
    std::cin.getline((char *) frame, 25);
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    strcpy(this->_manufacturer, reinterpret_cast<const char *>(manu));
    strcpy(this->_name, reinterpret_cast<const char *>(name));
    _year = year;
    _power = power;
    _size = size;
    strcpy(this->_frame, reinterpret_cast<const char *>(frame));
}