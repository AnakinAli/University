//
// Created by anakin on 20.02.24.
//

#ifndef PLANTHANDLER_H
#define PLANTHANDLER_H
#include "Flower.h"
#include "Tree.h"

struct TreeFlowerStruct {
    Tree* trees;
    int currentTreeIndex, currentFlowerIndex;
    Flower* flowers;
};

class PlantHandler {
private:
    TreeFlowerStruct treeFlowerStruct;

    void addNewPlantMenuOption() {
        // ask type
        int platType = getInput<int>("Select type plant: \n 1-Add tree\n 2-Add flower\n: ");
        if (platType == 1) {
            // make a tree
            Tree tree;
            tree.getTreeInformationFromInput();
            treeFlowerStruct.trees[treeFlowerStruct.currentTreeIndex++] = tree;
        }
        else {
            Flower flower;
            flower.getInputDataForFlower();
            treeFlowerStruct.flowers[treeFlowerStruct.currentFlowerIndex++] = flower;
        }
    }

    void listAllPlantData(TreeFlowerStruct treeFlowerStruct) {
        cout << "Listed Trees: " << endl;
        for (int i = 0; i < treeFlowerStruct.currentTreeIndex; i++) {
            treeFlowerStruct.trees[i].displayTreeData();
        }

        cout << "Listed Flowers: " << endl;
        for (int i = 0; i < treeFlowerStruct.currentFlowerIndex; i++) {
            treeFlowerStruct.flowers[i].displayFlowerData();
        }
    }

    void showSpecificTypeOfTrees(int type = 1) {
        cout << "Showing Specifc Trees: " << endl;

        for (int i = 0; i < treeFlowerStruct.currentTreeIndex; i++) {
            if (treeFlowerStruct.trees[i].getType() == type) {
                treeFlowerStruct.trees[i].displayTreeData();
            }
        }
    }

    TreeFlowerStruct getAllPlantsWithCountGreaterThan(int minCount = 10) {
        cout << "Plants with count greater than: " << minCount << endl;
        TreeFlowerStruct newTreeFlowerStruct{
            new Tree[treeFlowerStruct.currentTreeIndex], 0, 0,
            new Flower[treeFlowerStruct.currentFlowerIndex]
        };

        int indexTrees = 0;
        int indexFlowers = 0;
        for (int i = 0; i < treeFlowerStruct.currentTreeIndex; i++) {
            if (treeFlowerStruct.trees[i].getCount() >= minCount) {
                newTreeFlowerStruct.trees[indexTrees++] = treeFlowerStruct.trees[i];
            }
        }

        for (int i = 0; i < treeFlowerStruct.currentFlowerIndex; i++) {
            if (treeFlowerStruct.flowers[i].getCount() >= minCount) {
                treeFlowerStruct.flowers[indexFlowers++] = treeFlowerStruct.flowers[i];
            }
        }

        newTreeFlowerStruct.currentFlowerIndex = indexFlowers;
        newTreeFlowerStruct.currentTreeIndex = indexTrees;
        return newTreeFlowerStruct;
    }

    void showAllPlantsWithCountGreaterThan(TreeFlowerStruct treeFlowerStruct) {
        listAllPlantData(treeFlowerStruct);
        delete [] treeFlowerStruct.trees;
        delete [] treeFlowerStruct.flowers;
    }

public:
    PlantHandler(int defaultPlantsCount = 10) {
        treeFlowerStruct.currentTreeIndex = 0;
        treeFlowerStruct.currentFlowerIndex = 0;

        treeFlowerStruct.trees = new Tree[defaultPlantsCount];
        treeFlowerStruct.flowers = new Flower[defaultPlantsCount];
    }

    void showMenu() {
        string menu =
                "Select option: \n 1-Add new Plant\n 2-List all data\n 3-Show specific type of trees\n 4-Make new array with plants with count greater than 10\n 5-Quit\n ~: ";
        int command = getInput<int>(menu);
        if (command == 1) {
            addNewPlantMenuOption();
        }
        else if (command == 2) {
            listAllPlantData(treeFlowerStruct);
        }
        else if (command == 3) {
            int getTreeType = getInput<int>("Enter tree type (1-иглолистни,2-широколистни): ");
            showSpecificTypeOfTrees(getTreeType);
        }
        else if (command == 4) {
            int count = getInput<int>("Enter min plant count: ");
            showAllPlantsWithCountGreaterThan(getAllPlantsWithCountGreaterThan(count));
        }
        else if (command == 5) {
            exit(123);
        }
        showMenu();
    }

    ~PlantHandler() {
        delete [] treeFlowerStruct.trees;
        delete [] treeFlowerStruct.flowers;
    }
};


#endif //PLANTHANDLER_H
