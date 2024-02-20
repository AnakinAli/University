//
// Created by anakin on 20.02.24.
//

#ifndef FLOWER_H
#define FLOWER_H
#include "Plant.h"


class Flower : public Plant {
private:
    string color;

public:
    Flower(): Plant() {
        color = "no-flower-color";
    }

    Flower(string color, string name, float price, int count): Plant(name, price, count) {
        this->color = color;
    }

    void getInputDataForFlower() {
        Plant::getPlantInformationFromInput();
        color=getInput<string>("Enter flower color: ");
    }

    void displayFlowerData() {
        Plant::displayPlantData();
        cout<<"Flower\n Color: "<<color<<endl;
    }
};


#endif //FLOWER_H
