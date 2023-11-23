#include <iostream>
using namespace std;

// Prompt
template<typename T>
T getInput(const string&prompt) {
    T value;
    cout << prompt;
    cin >> value;
    return value;
}


int main() {
    int rows = getInput<int>("Въведи n: ");
    int cols = getInput<int>("Въведи m: ");
    double y[rows][cols];

    double T[rows];
    int c = 0;

    for (int row = 0; row < rows; row++) {
        T[row] = 0;
        for (int col = 0; col < cols; col++) {
            cout << endl << "---------" << "Ред: " << row + 1 << " Колона: " << col + 1 << "---------" << endl;

            y[row][col] = getInput<double>("Въведете стойност: ");
            if (y[row][col] < 0) {
                T[row] += y[row][col];
            }
        }
    }
    cout << endl;


    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << y[row][col] << " ";
        }
        cout << endl;
    }

    for (int row = 0; row < rows; row++) {
        cout << T[row] << endl;
    }
}
