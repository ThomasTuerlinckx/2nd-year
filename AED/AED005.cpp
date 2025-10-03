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

int diagonalCalc(int a) { // A MUST BE THE UPPER SQUARE
  int returnable;
  cout << "YSquare" << " " << YSquares(a) << " ";
  if (isPair(a)) {
    returnable = a - (2 * YSquares(a));
    returnable += 1;
  } else if (!isPair(a)) {
    returnable = a + (2 * YSquares(a));
  }
  return returnable;
}

int Xdiagonal(int a) { return -YSquares(a); }

int Ydiagonal(int(a)) {
  int y;
  return YSquares(a);
}

int main() {
  int num;
  cin >> num;
  int x, y;
  if (real_sqrt(num)) {
    if (!isPair(num)) {
      x = sqrt(num) - 1;
      x = x / 2;
      y = x;

    } else if (isPair(num)) {
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
    while (true) {
      if (real_sqrt(upper)) {
        break;
      } else
        upper++;
    }
    while (true) {
      if (real_sqrt(lower)) {
        break;
      } else
        lower--;
    }

    int Xmiddle, Ymiddle, middle, count = 0;
    middle = diagonalCalc(upper);
    Xmiddle = Xdiagonal(upper);
    Ymiddle = Ydiagonal(upper);

    x = 1;
    y = 1;

    cout << lower << " " << upper << " " << middle << " " << count << " ";
  }

  cout << "(" << x << "," << y << ")";
  return 0;
}
