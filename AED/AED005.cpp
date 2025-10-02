#include <cmath>
#include <iostream>
using namespace std;

bool real_sqrt(int a) {
  if (a < 0)
    return false;
  int root = static_cast<int>(std::sqrt(a));
  return root * root == a;
}

int main() { return 0; }
