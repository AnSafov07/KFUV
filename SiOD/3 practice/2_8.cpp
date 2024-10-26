#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    double x;
    double answer = 0;
    cout << "Введите значение n: "; cin >> n;
    cout << "Введите значение x: "; cin >> x;
    if (n < 1) {
        cout << "Ошибка, введено ненатуральное число n" << endl;
    }
    else {
        for (int i = 1; i < n; i++) {
            answer += pow(-1, i - 1) * (pow(x, i) / i);
        }
        cout << answer << endl;
    }
}
