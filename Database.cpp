//
// Created by Krzysztof Koźlik on 10/07/2021.
//

#include "Database.h"
#include "iostream"
#include "fstream"
#include "vector"
#include <iomanip>
#include <algorithm>


//Metoda Wyświetlająca pełną zawartość wektora pojazdów
void Database::print() {
    int i = 1;
    for (Vehicle *v: this->_vehicles) {// Pętla foreach
        if (i % 2 == 0) { std::cout << "\x1b[30;47m"; }
        std::cout << std::setw(4) << i << " |";
        v->describe();
        i++;
        std::cout << "\x1b[0m";
    }
    std::cout << "\n\n";

}

//Metoda Wczytująca obiekty z pliku binarnego
int Database::read() {
    std::vector<int> sizes;// Tymczasowy wektor na rozmiary obiektow
    unsigned long vectSize;// Zmienna Przechowująca ilosc elementow w wektorze
    std::string fileName = "records.dat";

    std::cout << "Podaj nazwę Pliku: ";
    std::cin >> fileName;

    //Otwarcie Pliku binarnego
    std::ifstream inFile;
    inFile.open(fileName, std::ios::in | std::ios::binary);

    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char *>(&vectSize), sizeof(unsigned long));// Wczytanie ilosci obiektow

        for (int i = 1; i <= vectSize; i++) {// Pętla for odczytująca rozmiary poszczegulnych obiektow w pliku
            int sizeTmp;
            inFile.read(reinterpret_cast<char *>(&sizeTmp), sizeof(int));
            sizes.push_back(sizeTmp);
        }

        // Wczytywanie Obiektów z pliku binnarnego według odczytanej wcześniej mapy pliku
        for (int i : sizes) {
            switch (i) {
                case 128: {
                    Car c1;// Tworzenie obiektu w pamięci stack
                    inFile.read(reinterpret_cast<char *>(&c1), i);// Wczytanie obiektu z pliku do pamięci stack
                    Car *c2 = new Car(c1);// Skopiowanie Obiektu z pamięci stack do heap
                    this->_vehicles.push_back(c2);// Zapisanie wskaznika obiektu do wektora pojazdów
                }
                    break;
                case 104: {
                    Bike b1;
                    inFile.read(reinterpret_cast<char *>(&b1), i);
                    Bike *b2 = new Bike(b1);
                    this->_vehicles.push_back(b2);
                }
                    break;
                case 80: {
                    Misc m1;
                    inFile.read(reinterpret_cast<char *>(&m1), i);
                    Misc *m2 = new Misc(m1);
                    this->_vehicles.push_back(m2);
                }
                    break;
                default: {
                    std::cout << "Błąd podczasz wczytywania plików!\n";
                    return 1;
                }
            }

        }
        inFile.close();
        std::cout << "Wczytano " << vectSize << " Obiektów z pliku!\n";
        return 0;
    } else {
        std::cout << "Bład plik nie otwarty!\n";
        return 3;
    }
}

//Metoda Zapisująca obiekty do pliku binarnego
int Database::save() {
    std::vector<int> sizes;// Tymczasowy wektor z rozmiarami obiektów
    unsigned long vectSize;// Zmienna z ilością obiektów
    std::string fileName = "records.dat";

    std::cout << "Podaj nazwę Pliku: ";
    std::cin >> fileName;

    std::ofstream outFile;
    outFile.open(fileName, std::ios::out | std::ios::binary);//Otwarcie pliku binarnego
    sizes.reserve(this->_vehicles.size());
    for (Vehicle *i : this->_vehicles) {// Pętla for zapisująca rozmiary obiektow głównego wektora do tymczasowego
        sizes.push_back(i->size());
    }
    vectSize = sizes.size();// Ilość elementów w wektorze

    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char *>(&vectSize),
                      sizeof(vectSize));// Zapisanie zmiennej z ilościa elemetow w pliku

        for (int i : sizes) {// Zapisanie mapy pliku
            outFile.write(reinterpret_cast<char *>(&i), sizeof(i));
        }
        for (Vehicle *i : this->_vehicles) {// Zapisanie obiektów do pliku
            outFile.write(reinterpret_cast<char *>(i), i->size());
        }
        outFile.close();
        return 0;
    } else {
        std::cout << "Błąd! Nie udało sie zapisać bazy danych do pliku!";
        return 1;
    }
}

//Metoda Dodająca Pojazd do pamięci i jego wskaznik do wektora
int Database::add() {
    int choice = 0;

    std::cout << "Samochód = 1\n";
    std::cout << "Rower = 2\n";
    std::cout << "Misc = 3\n";

    std::cout << "Wybierz rodzaj pojazdu do dodania\n";
    std::cin >> choice;
    switch (choice) {// Wybór obiektu do dodania
        case 1: {
            Car c1;//Utworzenie obiektu w pamięci stack
            c1.setData();//Wpisanie danych obiektu
            Car *c2 = new Car(c1);//Skopiowanie obiektu z pamięci stack do pamięci heap
            c2->describe();//Wyświetlenie obiektu
            this->_vehicles.push_back(c2);//Zapisanie wskaznika obiektu do wektora pojazdów
        }
            break;
        case 2: {
            Bike b1;
            b1.setData();
            Bike *b2 = new Bike(b1);
            b2->describe();
            this->_vehicles.push_back(b2);
        }
            break;
        case 3: {
            Misc m1;
            m1.setData();
            Misc *m2 = new Misc(m1);
            m2->describe();
            this->_vehicles.push_back(m2);
        }
            break;
        default: {
            std::cout << "Błąd! Nieprawidłowy typ pojazdu!";
        }
    }
    return 0;
}

//Metoda Usuwająca Pojazd z pamięci i wskaznik z wektora
int Database::del() {
    unsigned int index = 0;
    this->print();

    std::cout << "Podaj numer pojazdu do usunięcia (Wpisz 0 zeby anulować): ";
    std::cin >> index;

    if (index != 0) {
        index--;
        delete this->_vehicles[index];// usunięcie obiektu z pamięci
        this->_vehicles.erase(this->_vehicles.begin() + index);// usunięcie wskaznika obiektu w wektorze
        std::cout << "Usunięto Pojazd numer: " << index + 1 << ".\n";
    } else {
        return 1;
    }
    return 0;

}

int Database::sort(int key, bool rev) {
    if (this->_vehicles.size() > 1) {
        switch (key) {
            case 1:{
                if (rev) {
                    std::sort(this->_vehicles.begin(), this->_vehicles.end(), [](const auto &a, const auto &b) {
                        return a->_year < b->_year;
                    });
                } else {
                    std::sort(this->_vehicles.begin(), this->_vehicles.end(), [](const auto &a, const auto &b) {
                        return a->_year > b->_year;
                    });
                }
            }break;
            case 2: {
                if (rev) {
                    std::sort(this->_vehicles.begin(), this->_vehicles.end(), [](const auto &a, const auto &b) {
                        return a->_power < b->_power;
                    });
                } else {
                    std::sort(this->_vehicles.begin(), this->_vehicles.end(), [](const auto &a, const auto &b) {
                        return a->_power > b->_power;
                    });
                }
            }break;
            default:{
                std::cout << "Błędna Opcja!";
                return 1;
            }
        }
    } else {
        std::cout << "Błąd! Brak Pojazdów do posortowania\n";
        return 3;
    }
    return 0;
}


//Funkcja Menu odpowiedzialna za porusznaie sie po programie
int Database::menu() {
    int x;// zmienna wyboru menu

    std::cout << "\x1b[30;47m";
    std::cout << "1: WCZYTAJ PLIK | 2: ZAPISZ DO PLIKU | 3: WYŚWIETL BAZE DANYCH | 4: POSORTUJ BAZE DANYCH | "
              << "5: DODAJ NOWY POJAZD | 6: USUŃ POJAZD | 7: ZAMKNIJ PROGRAM\n";
    std::cout << "\x1b[0m";
    std::cout << "\nWYBIERZ OPCJE Z MENU: ";

    std::cin >> x;

    switch (x) {// Switch odpowiedzielny za wybór opcji
        case 1: {
            this->read();//Wczytanie Pliku
        }
            break;
        case 2: {
            this->save();//Zapisanie Pliku
        }
            break;
        case 3: {
            this->print();//Wyświetlanie Bazy Danych
        }
            break;
        case 4: {
            int sortChoice;
            int sortRev;
            std::cout << "\nSortowanie po: [1]Roczniku, [2]Mocy : ";
            std::cin >> sortChoice;
            if(sortChoice==1){
                std::cout << "\nOd: [1]Najstarszego, [2]Najmłodszego : ";
                std::cin >> sortRev;
                if(sortRev == 1) {
                    this->sort(1, true);
                }else if(sortRev == 2){
                    this->sort(1, false);
                }else{
                    std::cout << "Błąd! Zła metoda sortowania!";
                }
            }
            else if(sortChoice==2){
                std::cout << "\nOd: [1]Najsłabszego, [2]Najmocniejszego : ";
                std::cin >> sortRev;
                if(sortRev == 1) {
                    this->sort(0, true);
                }else if(sortRev == 2){
                    this->sort(0, false);
                }else{
                    std::cout << "Błąd! Zła metoda sortowania!";
                }
            }
            else{
                std::cout << "Błąd! Zła metoda sortowania!";
            }
        }
            break;
        case 5: {
            this->add();//Dodanie pojazdu
        }
            break;
        case 6: {
            this->del();//Usunięcie pojazdu
        }
            break;
        case 7: {
            return 1;
        }
        default: {
            std::cout << "Nieporawna Opcja Menu, uruchom program ponownie! \n";
            return 1;
        }
    }

    this->menu();
    return 0;
}
