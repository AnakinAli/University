//
// Created by anakin on 20.02.24.
//

#ifndef HOTEL_H
#define HOTEL_H
#include "Client.h"
#include "inputHandle.h"

#include <iostream>
using namespace std;

struct PaidOverFamilyClients {
    Client* clients;
    int count;
};

class Hotel {
private:
    Client* clients;
    int currentClientIndex;

public:
    Hotel(int defaultClientCount = 100) {
        clients = new Client[defaultClientCount];
        currentClientIndex = 0;
    }

    void addClient(Client client) {
        clients[currentClientIndex++] = client;
        cout << "Client: " << client.getName() << " \nAdded Succesfully!" << endl;
    }

    void showAllClients() {
        for (int i = 0; i < currentClientIndex; i++) {
            clients[i].display();
        }
    }

    void dispalyClientNamesBasedOnTown(string town = "no-town") {
        for (int i = 0; i < currentClientIndex; i++) {
            if (clients[i].getTown() == town && clients[i].getFamilyStatus()==1) {
                cout << "Name: " << clients[i].getName() << " Paid Price: " << clients[i].getStayPrice() << endl;
            }
        }
    }
    PaidOverFamilyClients getAllFamilyClientsThatPaidOver(float paidPrice=50) {
        PaidOverFamilyClients paidOverFamilyClients;
        paidOverFamilyClients.clients=new Client[getCountFamilyClients()];
        int count =0;
        for (int i=0;i<currentClientIndex;i++) {
            if(clients[i].getStayPrice()>=paidPrice) {
               paidOverFamilyClients.clients[count++]=clients[i];
            }
        }
        paidOverFamilyClients.count=count;

        return paidOverFamilyClients;
    }
    int getCountFamilyClients() {
        int c =0;
        for (int i=0;i<currentClientIndex;i++) {
            if(clients[i].getFamilyStatus()==2) {
                c++;
            }
        }
        return c;
    }

    ~Hotel() {
        delete [] clients;
    }
};


#endif //HOTEL_H
