#include <iostream>
using namespace std;

int factFunc(int n) {
  if (n == 1 || n == 0 || n < 1) {
    return 1;
  } else {
    return n * factFunc(n - 1);
  }
}

int main() {
  int num;
  int fact = 0;

  cout << "enter the number : ";
  cin >> num;

  fact = factFunc(num);

  cout << "factorial : " << fact;
}
