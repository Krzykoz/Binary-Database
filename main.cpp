#include <iostream>
#include <fstream>
#include <vector>
#include "pch.h"

void printVect(std::vector <Vehicle*>& vect){
    int i = 1;
    for(Vehicle* v: vect){
        std::cout << i << ". ";
        v->describe();
        i++;
    }
}

int read(std::vector <Vehicle*>& vect) {
    std::vector <int> sizes;
    unsigned long vectSize;
    std::string fileName = "records.dat";

    std::cout << "Podaj nazwę Pliku: ";
    std::cin >> fileName;

    std::ifstream inFile;
    inFile.open(fileName, std::ios::in | std::ios::binary);

    if(inFile.is_open()){
        inFile.read(reinterpret_cast<char*>(&vectSize), sizeof(unsigned long));

        for(int i = 1; i<=vectSize; i++){
            int sizeTmp;
            inFile.read(reinterpret_cast<char*>(&sizeTmp), sizeof(int));
            sizes.push_back(sizeTmp);
        }

        for(int i : sizes){
            switch (i) {
                case 128: {
                    Car c1;
                    inFile.read(reinterpret_cast<char *>(&c1), i);
                    Car *c2 = new Car(c1);
                    c2->describe();
                    vect.push_back(c2);
                }break;
                case 104: {
                    Bike b1;
                    inFile.read(reinterpret_cast<char *>(&b1), i);
                    Bike* b2 = new Bike(b1);
                    b2->describe();
                    vect.push_back(b2);
                }break;
                case 80: {
                    Other o1;
                    inFile.read(reinterpret_cast<char *>(&o1), i);
                    Other* o2 = new Other(o1);
                    o2->describe();
                    vect.push_back(o2);
                }break;
                default:{
                    std::cout << "Błąd podczasz wczytywania plików!\n";
                    return 1;
                }
            }

        }
        inFile.close();
        return 0;
    }else{
        std::cout << "Bład plik nie otwarty!\n";
        return 3;
    }
}

int save(std::vector <Vehicle *>& vehicles) {
    std::vector <int> sizes;
    unsigned long vectSize;
    std::string fileName = "records.dat";

    std::cout << "Podaj nazwę Pliku: ";
    std::cin >> fileName;

    std::ofstream outFile;
    outFile.open(fileName, std::ios::out | std::ios::binary);
    sizes.reserve(vehicles.size());
for(Vehicle *i : vehicles){
        sizes.push_back(i->size());
 }
    vectSize = sizes.size();

    if(outFile.is_open()){
        outFile.write(reinterpret_cast<char*>(&vectSize), sizeof(vectSize));

        for(int i : sizes){
            outFile.write(reinterpret_cast<char*>(&i), sizeof(i));
        }
        for(Vehicle *i : vehicles){
            outFile.write(reinterpret_cast<char*>(i), i->size());
        }
        outFile.close();
        return 0;
    }else{
        std::cout << "ERROR!";
        return 1;
    }
}

int addVech(std::vector <Vehicle *>& vect) {
    int choice = 0;

    std::cout << "Samochód = 1\n";
    std::cout << "Rower = 2\n";
    std::cout << "Int\n";

    std::cout << "Wybierz rodzaj pojazdu do dodania\n";
    std::cin >> choice;
    switch (choice) {
        case 1: {
            Car c1;
            c1.setData();
            Car *c2 = new Car(c1);
            c2->describe();
            vect.push_back(c2);
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
            std::cout << "Błąd w chuj";
        }
    }
    return 0;
}


int delVech(std::vector <Vehicle *>& vect){
    unsigned int index = 0;
    printVect(vect);

    std::cout << "Podaj numer pojazdu do usunięcia (Wpisz 0 zeby anulować): ";
    std::cin >> index;

    if(index!=0){
        index--;
        delete vect[index];
        vect.erase(vect.begin() + index);
        std::cout << "Usunięto Pojazd numer: " << index+1 << ".\n";
    }else{
        return 1;
    }
    return 0;

}

int menu(std::vector <Vehicle*>& vect){
    int x;
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

    switch(x){
        case 1:{
            read(vect);
        }break;
        case 2:{
            save(vect);
        }break;
        case 3:{
            printVect(vect);
        }break;
        case 4:{
            addVech(vect);
        }break;
        case 5:{
            delVech(vect);
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
    std::vector <Vehicle *> vehicles;

    menu(vehicles);


    return 0;

}