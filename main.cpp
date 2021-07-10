#include <iostream>
#include "pch.h"

//Funkcja Menu odpowiedzialna za porusznaie sie po programie
int menu(Database &vehicles){
    int x;// zmienna wyboru menu
    std::cout << "###########################################\n";
    std::cout << "#                                         #\n";
    std::cout << "#              1. Wczytaj Plik            #\n";
    std::cout << "#             2. Zapisz do Pliku          #\n";
    std::cout << "#          3. Wyśietl Baze Danych         #\n";
    std::cout << "#           4. Dodaj nowy pojazd          #\n";
    std::cout << "#               5. Usuń Pojazd            #\n";
    std::cout << "#             6. Zamknij Program          #\n";
    std::cout << "#                                         #\n";
    std::cout << "###########################################\n\n";

    std::cout << "Wybierz opcje z menu: ";
    std::cin >> x;

    switch(x){// Switch odpowiedzielny za wybór opcji
        case 1:{
            vehicles.read();//Wczytanie Pliku
        }break;
        case 2:{
            vehicles.save();//Zapisanie Pliku
        }break;
        case 3:{
            vehicles.print();//Wyświetlanie Bazy Danych
        }break;
        case 4:{
            vehicles.add();//Dodanie pojazdu
        }break;
        case 5:{
            vehicles.del();//Usunięcie pojazdu
        }break;
        case 6:{
            return 0;
        }break;
        default:{
            std::cout << "Nieporawna Opcja Menu, uruchom program ponownie! \n";
            return 1;
        }break;
    }

    menu(vehicles);
    return 0;
}

int main() {
    Database vehicles;

    menu(vehicles);// Wywołanie funkcji menu


    return 0;

}