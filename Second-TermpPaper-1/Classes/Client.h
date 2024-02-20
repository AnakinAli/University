//
// Created by anakin on 20.02.24.
//

#ifndef CLIENT_H
#define CLIENT_H


#include "string"
#include <iostream>
using namespace std;

class Client {
private:
    string name, egn, town;
    int familyStatus, countStaysInTheHotel;
    float stayPrice;

public:
    Client() {
        name = "no-name";
        egn = "no-egn";
        town = "no-town";
        familyStatus = 2;
        countStaysInTheHotel = -1;
        stayPrice = 50;
    }

    Client(string name, string egn, string town, int familyStatus, int countStaysInTheHotel, float stayPrice) {
        this->name = name;
        this->egn = egn;
        this->town = town;
        this->familyStatus = familyStatus;
        this->countStaysInTheHotel = countStaysInTheHotel;
        this->stayPrice = stayPrice;
    }

    void display() {
        cout << "Client: "
                << "\n Name: " << name
                << "\n Town: " << town
                << "\n Family Status: " << familyStatus
                << "\n Count Stays in Hotel: " << countStaysInTheHotel
                << "\n Stay Price: " << stayPrice << "\n EGN: " << egn
                << endl;
    }

    string getName() {
        return name;
    }

    float getStayPrice() {
        return stayPrice;
    }

    string getTown() {
        return town;
    }
    int getFamilyStatus() {
        return  familyStatus;
    }

};


#endif //CLIENT_H
