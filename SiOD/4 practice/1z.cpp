#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int x) {
    long long sum = 1;
    for (int i = 1; i <= x; i++) {
        sum *= i;
    }
    return sum;
}

long long sumfunc(double x, double E) {
    long long sum = 0;
    long long secsum = 0;
    long long limit = 100;
    for (int k = 0; k < limit; k++) {
        sum += pow(x, 2 * k) / (pow(2, k) * (factorial(k)));
        if (k >= 1) {
            for (int j = 0; j < limit; j++) {
                secsum += pow(x, 2 * j) / (pow(2, j) * (factorial(j))); 
            }
        }
        if (sum - secsum > E) {break;}
    }
    return sum;
}

int main() {
    double E, x;
    cout << "Введите значение x: "; cin >> x;
    cout <<  "Введите значение E: "; cin >> E;

    if (E <= 0 && x == 0) {
        cout << "Ошибка ввода данных!" << endl;
        return 0;
    } else if (x == 0) {
        cout << "Ошибка, Значение x не должно равняться 0!" << endl;
        return 0;
    } else if (E <= 0) {
        cout << "Ошибка, E должен быть строго больше 0!" << endl;
        return 0;
    } else {
        cout << "Приближенное значение бесконечной суммы: " << sumfunc(x, E) << endl;
    }
}
