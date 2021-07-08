#include <iostream>
#include <fstream>
#include <vector>
#include "pch.h"

//Funcja Wyświetlająca pełną zawartość wektora pojazdów
void printVect(std::vector <Vehicle*>& vect){
    int i = 1;
    for(Vehicle* v: vect){// Pętla foreach
        std::cout << i << ". ";
        v->describe();
        i++;
    }
}

//Funcja Wczytująca obiekty z pliku binarnego
int read(std::vector <Vehicle*>& vect) {
    std::vector <int> sizes;// Tymczasowy wektor na rozmiary obiektow
    unsigned long vectSize;// Zmienna Przechowująca ilosc elementow w wektorze
    std::string fileName = "records.dat";

    std::cout << "Podaj nazwę Pliku: ";
    std::cin >> fileName;

    //Otwarcie Pliku binarnego
    std::ifstream inFile;
    inFile.open(fileName, std::ios::in | std::ios::binary);

    if(inFile.is_open()){
        inFile.read(reinterpret_cast<char*>(&vectSize), sizeof(unsigned long));// Wczytanie ilosci obiektow

        for(int i = 1; i<=vectSize; i++){// Pętla for odczytująca rozmiary poszczegulnych obiektow w pliku
            int sizeTmp;
            inFile.read(reinterpret_cast<char*>(&sizeTmp), sizeof(int));
            sizes.push_back(sizeTmp);
        }

        // Wczytywanie Obiektów z pliku binnarnego według odczytanej wcześniej mapy pliku
        for(int i : sizes){
            switch (i) {
                case 128: {
                    Car c1;// Tworzenie obiektu w pamięci stack
                    inFile.read(reinterpret_cast<char *>(&c1), i);// Wczytanie obiektu z pliku do pamięci stack
                    Car *c2 = new Car(c1);// Skopiowanie Obiektu z pamięci stack do heap
                    vect.push_back(c2);// Zapisanie wskaznika obiektu do wektora pojazdów
                }break;
                case 104: {
                    Bike b1;
                    inFile.read(reinterpret_cast<char *>(&b1), i);
                    Bike* b2 = new Bike(b1);
                    vect.push_back(b2);
                }break;
                case 80: {
                    Other o1;
                    inFile.read(reinterpret_cast<char *>(&o1), i);
                    Other* o2 = new Other(o1);
                    vect.push_back(o2);
                }break;
                default:{
                    std::cout << "Błąd podczasz wczytywania plików!\n";
                    return 1;
                }
            }

        }
        inFile.close();
        std:: cout << "Wczytano " << vectSize << " Obiektów z pliku!\n";
        return 0;
    }else{
        std::cout << "Bład plik nie otwarty!\n";
        return 3;
    }
}

//Funcja Zapisująca obiekty do pliku binarnego
int save(std::vector <Vehicle *>& vehicles) {
    std::vector <int> sizes;// Tymczasowy wektor z rozmiarami obiektów
    unsigned long vectSize;// Zmienna z ilością obiektów
    std::string fileName = "records.dat";

    std::cout << "Podaj nazwę Pliku: ";
    std::cin >> fileName;

    std::ofstream outFile;
    outFile.open(fileName, std::ios::out | std::ios::binary);//Otwarcie pliku binarnego
    sizes.reserve(vehicles.size());
for(Vehicle *i : vehicles){// Pętla for zapisująca rozmiary obiektow głównego wektora do tymczasowego
        sizes.push_back(i->size());
 }
    vectSize = sizes.size();// Ilość elementów w wektorze

    if(outFile.is_open()){
        outFile.write(reinterpret_cast<char*>(&vectSize), sizeof(vectSize));// Zapisanie zmiennej z ilościa elemetow w pliku

        for(int i : sizes){// Zapisanie mapy pliku
            outFile.write(reinterpret_cast<char*>(&i), sizeof(i));
        }
        for(Vehicle *i : vehicles){// Zapisanie obiektów do pliku
            outFile.write(reinterpret_cast<char*>(i), i->size());
        }
        outFile.close();
        return 0;
    }else{
        std::cout << "Błąd! Nie udało sie zapisać bazy danych do pliku!";
        return 1;
    }
}

//Funkcja Dodająca Pojazd do pamięci i jego wskaznik do wektora
int addVech(std::vector <Vehicle *>& vect) {
    int choice = 0;

    std::cout << "Samochód = 1\n";
    std::cout << "Rower = 2\n";
    std::cout << "Other = 3\n";

    std::cout << "Wybierz rodzaj pojazdu do dodania\n";
    std::cin >> choice;
    switch (choice) {// Wybór obiektu do dodania
        case 1: {
            Car c1;//Utworzenie obiektu w pamięci stack
            c1.setData();//Wpisanie danych obiektu
            Car *c2 = new Car(c1);//Skopiowanie obiektu z pamięci stack do pamięci heap
            c2->describe();//Wyświetlenie obiektu
            vect.push_back(c2);//Zapisanie wskaznika obiektu do wektora pojazdów
        }
            break;
        case 2: {
            Bike b1;
            b1.setData();
            Bike *b2 = new Bike(b1);
            b2->describe();
            vect.push_back(b2);
        }
            break;
        case 3: {
            Other o1;
            o1.setData();
            Other *o2 = new Other(o1);
            o2->describe();
            vect.push_back(o2);
        }
            break;
        default: {
            std::cout << "Błąd! Nieprawidłowy typ pojazdu!";
        }
    }
    return 0;
}

//Funkcja Usuwająca Pojazd z pamięci i wskaznik z wektora
int delVech(std::vector <Vehicle *>& vect){
    unsigned int index = 0;
    printVect(vect);

    std::cout << "Podaj numer pojazdu do usunięcia (Wpisz 0 zeby anulować): ";
    std::cin >> index;

    if(index!=0){
        index--;
        delete vect[index];// usunięcie obiektu z pamięci
        vect.erase(vect.begin() + index);// usunięcie wskaznika obiektu w wektorze
        std::cout << "Usunięto Pojazd numer: " << index+1 << ".\n";
    }else{
        return 1;
    }
    return 0;

}

//Funkcja Menu odpowiedzialna za porusznaie sie po programie
int menu(std::vector <Vehicle*>& vect){
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
            read(vect);//Wczytanie Pliku
        }break;
        case 2:{
            save(vect);//Zapisanie Pliku
        }break;
        case 3:{
            printVect(vect);//Wyświetlanie Bazy Danych
        }break;
        case 4:{
            addVech(vect);//Dodanie pojazdu
        }break;
        case 5:{
            delVech(vect);//Usunięcie pojazdu
        }break;
        case 6:{
            return 0;
        }break;
        default:{
            std::cout << "Nieporawna Opcja Menu, uruchom program ponownie! \n";
            return 1;
        }break;
    }

    menu(vect);
    return 0;
}

int main() {
    std::vector <Vehicle *> vehicles; // Wektor wskaźników pojazdów

    menu(vehicles);// Wywołanie funkcji menu


    return 0;

}