//
// Created by anakin on 20.02.24.
//

#ifndef PLANT_H
#define PLANT_H

// наименование, цена, брой
#include "string"
#include "inputHandle.h"

using namespace std;

class Plant {
protected:
    string name;
    float price;
    int count;

public:
    Plant() {
        name = "no-plant-name";
        price = 0;
        count = 0;
    }

    Plant(string name, float price, int count): name(name), price(price), count(count) {
    }

    void getPlantInformationFromInput() {
        name = getInput<string>("Enter Plant name: ");
        price = getInput<float>("Enter Plant price: ");
        count = getInput<int>("Enter Plant count: ");
    }

    int getCount() {
        return count;
    }

    void displayPlantData() {
        cout << "Plant\n Name: " << name << "\n Price: " << price << "\n Count: " << count << endl;
    }
};


#endif //PLANT_H
