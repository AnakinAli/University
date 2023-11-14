#include <complex>
#include <iostream>
using namespace std;

template<typename T>
T getInput(const string&prompt) {
    T value;
    cout << prompt;
    cin >> value;
    return value;
}

/**
    Съставете алгоритъм и напишете програма за
    въвеждане координатите на точки и извеждане на екрана координатите на онези от тях, които не лежат в защрихованата област.
    Въвеждането се прекратява,
    когато броят въведените точки стане най-малко М и броят на лежащите защрихованата област стане N.
 */

bool secondQuadrant(double x, double y, double a) {
    return x < 0 && y > 0 && abs(x) > a && x < -y;
}

bool thirdQuadrant(double x, double y, double a) {
    return x < 0 && y < 0 && (abs(y) > a || abs(x) > a);
}

bool forthQuadrant(double x, double y, double a) {
    return x > 0 && y < 0 && abs(y) > a && y < -x;
}

bool isPointInShadedArea(double x, double y, double a) {
    return secondQuadrant(x, y, a) || thirdQuadrant(x, y, a) || forthQuadrant(x, y, a);
}

bool isPointInCircle(double x, double y, double r) {
    return sqrt(pow(x, 2) + pow(y, 2)) <= r;
}


int main() {
    system('chcp 1251');
    int M = getInput<int>("Въведи M: ");
    int N = getInput<int>("Въведи N: ");
    double r = getInput<double>("Въведи радиуса на окръзноста: ");
    double a = getInput<double>("Въведи a: ");

    double** validPoints = new double *[M];

    int countEnteredPoints = 0, countInShadeAreaPoints = 0, countValidPoints = 0;

    while (countEnteredPoints <= M && countInShadeAreaPoints <= N) {
        cout << endl << "#" << countEnteredPoints << " Точка:  " << endl;

        double x = getInput<double>("Въведи x: ");
        double y = getInput<double>("Въведи y: ");

        if (!isPointInCircle(x, y, r)) {
            cout << "Невалидна точка: (" << "x= " << x << " y= " << y << ")" << endl;
            continue;
        }
        if (isPointInShadedArea(x, y, a)) {
            countInShadeAreaPoints++;
        }
        else {
            cout << "Валидна Точка: (" << " x: " << x << " y: " << y << ")" << endl;

            validPoints[countValidPoints] = new double[2];
            validPoints[countValidPoints][0] = x;
            validPoints[countValidPoints][1] = y;

            countValidPoints++;
        }
        countEnteredPoints++;
    }

    //get the points
    for (int i = 0; i < countValidPoints; i++) {
        cout <<"#"<<i+1 <<": Точка (x,y): " << "(" << validPoints[i][0] << "," << validPoints[i][1] << ")" << endl;
    }

    //delete dynamic array
    for (int i = 0; i < countValidPoints; ++i) {
        delete [] validPoints[i];
    }
    delete validPoints;

    return 0;
}
