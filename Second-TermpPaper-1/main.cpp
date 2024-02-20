#include <iostream>
#include "Classes/Hotel.h"
#include "Classes/inputHandle.h"
using namespace std;

int main() {
    Hotel hotel;
    Client client;
    hotel.addClient(client);
    hotel.showAllClients();
    hotel.dispalyClientNamesBasedOnTown();
    PaidOverFamilyClients specialClients = hotel.getAllFamilyClientsThatPaidOver();

    for (int i = 0; i < specialClients.count; i++) {
        specialClients.clients[i].display();
    }

    delete [] specialClients.clients;
    return 0;
}
