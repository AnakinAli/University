//
// Created by anakin on 20.02.24.
//

#ifndef TREE_H
#define TREE_H
#include "Plant.h"


class Tree : public Plant {
private:
    double height;
    int type; //1 - iglo 2-shir

    string getTreeType() {
        return type == 1 ? "иглолистни" : "широколистни";
    }

public:
    Tree(): Plant() {
        height = 0;
        type = 0;
    }

    Tree(string name, float price, int count, double height, int type): Plant(name, price, count) {
        this->height = height;
        this->type = type;
    }

    void getTreeInformationFromInput() {
        Plant::getPlantInformationFromInput();

        height = getInput<double>("Enter tree height: ");
        type = getInput<int>("Enter tree type(1-иглолистни, 2-широколистни): ");
    }

    int getType() {
        return type;
    }

    void displayTreeData() {
        Plant::displayPlantData();
        cout << "Tree\n Height: " << height << "\n Type: " << getTreeType() << endl;
    }
};


#endif //TREE_H
