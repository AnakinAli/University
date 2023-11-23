#include <iostream>
#include <math.h>
using namespace std;

// Prompt
template<typename T>
T getInput(const string&prompt) {
    T value;
    cout << prompt;
    cin >> value;
    return value;
}

bool isPointInCircle(double x, double y, double h, double k, double r) {
    return sqrt(pow(x - h, 2) + pow(y - k, 2)) <= r;
}

int** updateCircleIdPointsCounter(int circleId, int** &array, int rows) {
    for (int row = 0; row < rows; row++) {
        if (array[row][0] == circleId) {
            array[row][1]++;
        }
    }
    return array;
}

bool isCircleIdInArray(int** array, int rows, int circleId) {
    for (int row = 0; row < rows; row++) {
        if (array[row][0] == circleId) {
            return true;
        }
    }
    return false;
}

int main() {
    // Get number of circles
    int k = getInput<int>("Въведете брой на окръжности: ");

    double** circleData = new double *[k];

    //get circles
    for (int i = 0; i < k; i++) {
        cout << endl << "-----------#" << i + 1 << "---------" << endl;

        cout << "Въведете данните на окръжността: " << endl;


        circleData[i] = new double[3];
        circleData[i][0] = getInput<double>("Въведете x: ");
        circleData[i][1] = getInput<double>("Въведете y: ");
        circleData[i][2] = getInput<double>("Въведете r: ");
    }
    cout << endl;

    //Get number of points
    int m = getInput<int>("Въведете брой на точките: ");

    // create the array
    double** points = new double *[m];

    //get points
    for (int i = 0; i < m; i++) {
        cout << endl << "---------" << "#" << i + 1 << "---------" << endl;
        cout << "Въведете данните на точката: " << endl;

        points[i] = new double[2];

        points[i][0] = getInput<double>("Въведете x: ");
        points[i][1] = getInput<double>("Въведете y: ");
    }
    cout << endl;


    int** countPointsInCircle = new int *[k];
    int counter = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            if (isPointInCircle(points[i][0], points[i][1], circleData[j][0], circleData[j][1], circleData[j][2])) {
                cout << "Точка (x=" << points[i][0] << ", y=" << points[i][1] << ") лежи в кръг номер: " << j << endl;

                if (!isCircleIdInArray(countPointsInCircle, counter, j)) {
                    countPointsInCircle[counter] = new int[2];
                    countPointsInCircle[counter][0] = j;
                    countPointsInCircle[counter][1] = 1;
                    counter++;
                }
                else {
                    updateCircleIdPointsCounter(j, countPointsInCircle, counter);
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << "Кръг #" << countPointsInCircle[i][0] << " има " << countPointsInCircle[i][1] << " точка/и!" << endl;
    }


    // Delete dynamic arrays
    for (int i = 0; i < k; i++) {
        delete [] circleData[i];
    }
    delete circleData;

    for (int i = 0; i < counter; i++) {
        delete [] countPointsInCircle[i];
    }
    delete countPointsInCircle;

    for (int i = 0; i < m; i++) {
        delete [] points[i];
    }
    delete points;
}
