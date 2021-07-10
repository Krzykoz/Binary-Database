#include "pch.h"
#include <iostream>
//setlocale(LC_ALL, "polish"); //Polskie znaki w konsoli [Windows: on] [macOS: off]

template<class T, class U = T>
void Test(T &a, U &b) {
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
};

int main() {
    Database vehicles;// Obiekt z bazą danych pojazdów    std::cout << "\x1b[31;44m";

    Test("test1", "test2");

    vehicles.menu();// Wywołanie Metody Menu klasy Databases

    return 0;

}
