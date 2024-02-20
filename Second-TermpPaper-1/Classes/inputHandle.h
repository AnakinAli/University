//
// Created by anakin on 20.02.24.
//

#ifndef INPUTHANDLE_H
#define INPUTHANDLE_H

#include <iostream>
using namespace std;


template<typename T>
T getInput(const string& prompt) {
    T value;
    cout << prompt;
    cin >> value;
    cout << endl;
    return value;
}

#endif //INPUTHANDLE_H
