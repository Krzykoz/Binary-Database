#include <iostream>
#include <fstream>
#include <vector>
#include "pch.h"

void save(std::vector <Vehicle *>& vehicles) {
    std::vector <int> sizes;
    int vectSize;

    std::ofstream outFile;
    outFile.open("records.dat", std::ios::out | std::ios::binary);
    sizes.reserve(vehicles.size());
for(Vehicle *i : vehicles){
        sizes.push_back(i->size());
 }
    vectSize = sizes.size();
    std::cout << vectSize;

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

int read(std::vector <Vehicle*>& vect) {
    std::vector <int> sizes;
    int vectSize;

    std::ifstream inFile;
    inFile.open("records.dat", std::ios::in | std::ios::binary);

    if(inFile.is_open()){
        inFile.read(reinterpret_cast<char*>(&vectSize), sizeof(int));

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
                    Car* c1 = new Car();
                    inFile.read(reinterpret_cast<char*>(c1), i);
                    //c1->describe();
                    vect.push_back(c1);
                }break;
                case 104: {
                    std::cout << "Otwieram rower o rozmairze: "<< i << "\n";
                    Bike* b1 = new Bike();
                    inFile.read(reinterpret_cast<char *>(b1), i);
                    b1->describe();
                    vect.push_back(b1);
                }break;
                case 80: {
                    std::cout << "Otwieram other o rozmairze: "<< i << "\n";
                    Other* o1 = new Other();
                    inFile.read(reinterpret_cast<char *>(o1), i);
                    //o1->describe();
                    vect.push_back(o1);
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

int main() {
    std::vector <Vehicle *> vehicles;

    Car car("Tesla", "Model S", 2021, 1020.0f, "Sedan", "Solar Red", 5, 3);
    Car car1("Hiundai", "jakis S", 2021, 1020.0f, "Sedan", "Solar Red", 5, 3);
    Bike bike("Korss", "E-Bike MTB", 2020, 0.3f, 27, "Aluminium");

    Other other("Xiaomi", "Mi Electric Scooter", 2018, 0.05f, 20, 5200);

    vehicles.push_back(&car);
    vehicles.push_back(&bike);
    vehicles.push_back(&other);
    vehicles.push_back(&car1);
    vehicles.push_back(&car);
    vehicles.push_back(&car1);
    for(Vehicle* i: vehicles){
        i->describe();
    }



    //save(vehicles);
    std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";
    read(vehicles);
    std::cout << "\n//////////////////////////////////////////////////////////////////////////////// \n\n";

    for(Vehicle* i: vehicles){
        i->describe();
    }

    return 0;

}