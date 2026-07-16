#include "iostream"
using namespace std;

int findGCD(int a, int b) {
  if (b == 0) {
    return a;
  }

  return findGCD(b, a % b);
}

int main() {
  int a = 10;
  int b = 4;

  cout << findGCD(a, b) << endl;
}
