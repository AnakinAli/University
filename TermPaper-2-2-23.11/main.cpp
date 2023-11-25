#include <iostream>
using namespace std;

// Prompt
template<typename T>
T getInput(const string& prompt) {
    T value;
    cout << prompt;
    cin >> value;
    return value;
}

int main() {
    //system("chcp 1251");
    int rows = getInput<int>("Въведи n: ");
    int cols = getInput<int>("Въведи m: ");
    double** y = new double*[rows];
    double** T = new double*[rows];

    for (int row = 0; row < rows; row++) {
        T[row] = new double[1]{0};
        y[row] = new double[cols];
        for (int col = 0; col < cols; col++) {
            cout << endl << "---------" << "Ред: " << row + 1 << " Колона: " << col + 1 << "---------" << endl;

            y[row][col] = getInput<double>("Въведете стойност: ");
            if (y[row][col] < 0) {
                T[row][0] += y[row][col];
            }
        }
    }
    cout << endl;

    cout << "--------------------" << endl;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << y[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int row = 0; row < rows; row++) {
        cout << "Ред №_" << row + 1 << ": " << T[row][0] << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] y[i];
    }
    delete[] y;
    for (int i = 0; i < rows; i++) {
        delete[] T[i];
    }
    delete[] T;
}
