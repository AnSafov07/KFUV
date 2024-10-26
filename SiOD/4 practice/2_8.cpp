#include <iostream>
#include <cmath>
using namespace std;

long double sumfunc(long double x, long double E) {
    long double sum = 0;
    long double secsum = 0;
    long double limit = 1000000;
    long double highsum = 1 / (1 + x);
    
    for (int n = 0; n < limit; n++) {
        sum += pow((-1), n) * pow(x, n);
        if (n >= 1) {
            for (int j = 0; j < limit; j++) {
                secsum += pow((-1), n) * pow(x, n); 
            }
        }
        if (sum - secsum > E) {break;}
    }
    cout << endl;
    cout << "Приближенное значение бесконечной суммы: " << sum << endl;
    cout << "Значение по формуле: " << highsum << endl;
    cout << "Разность значений: " << fabs(highsum - sum);
    
    return sum;
}

int main() {
    long double E, x;
    cout << "Введите х ∈ (-1;1): "; cin >> x;
    cout <<  "Введите значение E: "; cin >> E;

    if (E <= 0 && ((x < -1) || (x > 1))) {
        cout << "Ошибка ввода данных!" << endl;
        return 0;
    } else if ((x < -1) || (x > 1)) {
        cout << "Ошибка, Значение x не находится в диапазоне (-1;1) !" << endl;
        return 0;
    } else if (E <= 0) {
        cout << "Ошибка, E должен быть строго больше 0!" << endl;
        return 0;
    } else {
        sumfunc(x, E);
    }
}
