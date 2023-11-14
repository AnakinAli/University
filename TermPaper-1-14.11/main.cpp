#include <iostream>
using namespace std;

/**
    Мечо Пух решил да си отбелязва колко пити мед излапва за един месец.
    Всеки ден той отваря по един кошер, който съдържа най-много 5 пити мед.
    Бедата била, че Пух не знаел числата. затова използвал негов си начин за записване.
    Той отбелязвал 1 излапана пита с точка, 2 излапани пити - със символа "^", 3 - с "+", 4 - "*" и 5 - с "х".
    Понякога кошерът се оказвал празен и тогава Мечо Пух оставал гладен.
    В края на месеца Пух установил, че не може да пресметне колко пити мед е излапал този месец.
    Помогнете му, като съставите алгоритъм и напишете програма, която
    получава отбелязаните символи за месеца и намира броя излапани пити от Мечо Пух за месеца.
    Например, ако Мечо Пух е отбелязал *+^^.. излапаните пити е 13.
 */

int getCount(const char symbol) {
    int r = 1;

    switch (symbol) {
        case '^':
            r = 2;
            break;
        case '+':
            r = 3;
            break;
        case '*':
            r = 4;
            break;
        case 'x':
            r = 5;
            break;
        default:
            r = 0;
            break;
    }
    return r;
}

int main() {
    string commands;
    int countEatenFood = 0;

    cout << "Enter symbols: ";
    cin >> commands;
    cout << endl;

    const int length = commands.length();

    for (int i = 0; i < length; i++) {

        countEatenFood += getCount(commands[i]);
    }

    cout << "Count eaten food: " << countEatenFood << endl;

    return 0;
}
