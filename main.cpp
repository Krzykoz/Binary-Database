#include "pch.h"
//setlocale(LC_ALL, "polish"); //Polskie znaki w konsoli [Windows: on] [macOS: off]

int main() {
    Database vehicles;// Obiekt z bazą danych pojazdów    std::cout << "\x1b[31;44m";

    vehicles.menu();// Wywołanie Metody Menu klasy Databases

    return 0;

}
