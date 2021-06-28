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

    std::ifstream inFile;
    inFile.open("records.dat", std::ios::in | std::ios::binary);

    if(inFile.is_open()){
        inFile.read(reinterpret_cast<char*>(&vectSize), sizeof(unsigned long));

        for(int i = 1; i<=vectSize; i++){
            int sizeTmp;
            inFile.read(reinterpret_cast<char*>(&sizeTmp), sizeof(int));
            sizes.push_back(sizeTmp);
        }

        for(int i : sizes){
            std::cout << "rozmiar obiektu: "<< i << "\n";
            switch (i) {
                case 128: {
                    std::cout << "Otwieram Fure o rozmairze: "<< i << "\n";
                    Car c1;
                    inFile.read(reinterpret_cast<char *>(&c1), i);
                    Car *c2 = new Car(c1);
                    c2->describe();
                    vect.push_back(c2);
                }break;
                case 104: {
                    std::cout << "Otwieram rower o rozmairze: "<< i << "\n";
                    Bike b1;
                    inFile.read(reinterpret_cast<char *>(&b1), i);
                    Bike* b2 = new Bike(b1);
                    b2->describe();
                    vect.push_back(b2);
                }break;
                case 80: {
                    std::cout << "Otwieram other o rozmairze: "<< i << "\n";
                    Other o1;
                    inFile.read(reinterpret_cast<char *>(&o1), i);
                    Other* o2 = new Other(o1);
                    o2->describe();
                    vect.push_back(o2);
                }break;
                default:{
                    std::cout << "Błąd w chuj";
                    return 1;
                }
            }

        }
        inFile.close();
        return 0;
    }else{
        std::cout << "ERROR!";
        return 3;
    }
}

void save(std::vector <Vehicle *>& vehicles) {
    std::vector <int> sizes;
    unsigned long vectSize;

    std::ofstream outFile;
    outFile.open("records.dat", std::ios::out | std::ios::binary);
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
    }else{
        std::cout << "ERROR!";
    }
}

int delVech(std::vector <Vehicle *>& vect){
    int index = 0;
    printVect(vect);


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
            std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";
            read(vect);
            std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";
        }break;
        case 2:{
            std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";
            save(vect);
            std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";
        }break;
        case 3:{
            std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";
            printVect(vect);
            std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";
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