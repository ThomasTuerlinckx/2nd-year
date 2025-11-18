#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void Helper(const int a) {
  int div = 2, res = a;
  bool first = true;
  for (int i = 0; i < sqrt(a); i++) {
    if (res % div == 0 and first == true) {
      cout << div;
      res = res / div;
      first = false;
    }
    if (res % div == 0) {
      cout << "*" << div;
      res = res / div;
    } else {
      div++;
    }
  }
  for (int i = sqrt(a); i < a / 2 + 1; i++) {
    if (res % div == 0) {
      cout << div;
      break;
    } else {
      div++;
    }
  }
}

int main() {
  int a, number;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> number;

    return 0;
  }
}
