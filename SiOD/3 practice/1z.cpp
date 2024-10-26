#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int factorial(int x) {
  cpp_int sum = 1;
  for (int i = 1; i <= x; i++) {
    sum *= i;
  }
  return sum;
}

cpp_dec_float_50 part(int x) {
  cpp_dec_float_50 x_full;
  cpp_dec_float_50 x_znamenatel = 1;
  for (int i = 2; i <= x; i++) {
    x_znamenatel += cpp_dec_float_50(1) / cpp_dec_float_50(i);
  }
  if (x_znamenatel != 0) {
    x_full = cpp_dec_float_50(factorial(x)) / x_znamenatel;
  } else {
    return 0;
  }
  return x_full;
}

int main() {
  setlocale(LC_ALL, "Russian"); 
  int n = 0;
  cout << "Введите число n: ";
  cin >> n;
  
  cout << part(n) << endl;
  return 0;
}
