#include "Car.h"
#include <iostream>
#include <cstring>
#include <iomanip>

//Konstruktor Domyślny
Car::Car() = default;

//Destruktor Domyślny
Car::~Car()= default;

//Konstruktor Kopiujący
Car::Car(const Car& src)
    : Vehicle(src._manufacturer, src._name, src._year, src._power), _seats(src._seats), _motors(src._motors) {
    strcpy(_body, src._body);
    strcpy(_color, src._color);
}

//Konstruktor
Car::Car(const char manufacturer[25], const char name[25],
         unsigned year, float power,const char body[25],
         const char color[25], unsigned seats, unsigned motors)
    : Vehicle(manufacturer, name, year, power), _seats(seats), _motors(motors) {
    strcpy(_body, body);
    strcpy(_color, color);
}

//Przeładowanie operatora "="
Car& Car::operator=(const Car & src) {
    strcpy(this->_body, src._body);
    strcpy(this->_color, src._color);
    strcpy(this->_name, src._name);
    strcpy(this->_manufacturer, src._manufacturer);
    this->_power = src._power;
    this->_seats = src._seats;
    this->_motors = src._motors;
    this->_year = src._year;
    return *this;
}

//Wyświetlania dancyh obiektów
void Car::describe() {
    std::cout << std::setw(10) << this->_manufacturer << " | " << std::setw(20) << this->_name << " | "
    <<  std::setw(4) << this->_year << " | " << std::setw(6) << this->_power << " HP | Nadwozie:"
    << std::setw(10) <<this->_body << " | Kolor:" << std::setw(15) << this->_color << " | Miejsca:"
    << std::setw(3)<< this->_seats << " | Silniki: " << std::setw(1) << this->_motors << "\n";
}

//Metoda zwracająca rozmiar obiektu
int Car::size() {
    return sizeof(*this);
}

//Metoda Pozwalająca ręcznie wpisać danie do obiektu
int Car::setData(){
    const char *manu[25];
    const char *name[25];
    unsigned year;
    float power;
    const char *body[25];
    const char *color[25];
    unsigned seats;
    unsigned motors;



    std::cout << "\nPodaj nazwę producenta samochodu: ";
    std::cin >> (signed char *) manu;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj nazwę samochodu: ";
    std::cin >> (signed char *) name;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj rok produkcji samochodu: ";
    std::cin >> year;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";

        return 1;
    }

    std::cout << "\nPodaj moc samochodu: ";
    std::cin >> power;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj rodzaj nadowzia samochodu: ";
    std::cin >> (signed char *) body;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj kolor karoseri samochodu: ";
    std::cin >> (signed char *) color;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj ilość miejsc w samochodzie: ";
    std::cin >> seats;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    std::cout << "\nPodaj ilość silników w samochodzie: ";
    std::cin >> motors;
    if(std::cin.fail()){
        std::cout << "\nBłąd! Błędne dane!\n";
        return 1;
    }

    strcpy(this->_manufacturer, reinterpret_cast<const char *>(manu));
    strcpy(this->_name, reinterpret_cast<const char *>(name));
    _year = year;
    _power = power;
    strcpy(this->_body, reinterpret_cast<const char *>(body));
    strcpy(this->_color, reinterpret_cast<const char *>(color));
    _seats = seats;
    _motors = motors;

    return 0;
}