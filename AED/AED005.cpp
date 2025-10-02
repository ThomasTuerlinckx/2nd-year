#include <cmath>
#include <complex>
#include <iostream>
using namespace std;

bool real_sqrt(int a) {
  if (a < 0)
    return false;
  int root = static_cast<int>(sqrt(a));
  return root * root == a;
}

bool isPair(int a) {
  if (a % 2 == 0) {
    return true;
  } else
    return false;
}

int YSquares(int num) {
  if (isPair(num)) {
    int y = (sqrt(num) - 1) / 2;
    return y;
  } else {
    int y = sqrt(num) / 2;
    y = -y;
    return y;
  }
}

int main() {
  int num;
  cin >> num;
  int x, y;
  if (real_sqrt(num)) {
    if (isPair(num)) {
      x = sqrt(num) - 1;
      x = x / 2;
      y = x;

    } else {
      y = sqrt(num) / 2;
      y = -y;
      x = y + 1;
    }
  }

  else {
    int lower = num;
    int upper = num;
    bool up = false;
    bool down = false;
    while (up == false or down == false) {
      if (real_sqrt(lower) != false) {
        lower--;
      } else
        down = true;

      if (real_sqrt(upper)) {
        upper--;
      } else
        up = true;
    }

    int Xmiddle, Ymiddle;
    if (isPair(upper)) {
      int Yupper = YSquares(upper);
      Xmiddle = -Yupper;
      Ymiddle = Yupper;

      if (!isPair(upper)) {
        int Yupper = YSquares(upper);
        Xmiddle = -Yupper;
        Ymiddle = Yupper;
      }
    }
  }

  cout << "(" << x << "," << y << ")";
  return 0;
}
