#include <cmath>
#include <iostream>
using namespace std;

bool real_sqrt(int a) {
  if (a < 0)
    return false;
  int root = static_cast<int>(sqrt(a));
  return root * root == a;
}

int main() {
  int num;
  cin >> num;
  int x, y;
  if (real_sqrt(num)) {
    if (num % 2 != 0) {
      x = sqrt(num) - 1;
      x = x / 2;
      y = x;

    } else {
      y = sqrt(num) / 2;
      y = -y;
      x = y + 1;
    }
  }

  cout << "(" << x << "," << y << ")";
  return 0;
}
