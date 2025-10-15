#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, S, I;
  cin >> N >> S >> I;

  string chests;
  cin >> chests;

  int pos = S - 1;
  int left = pos;
  int right = pos;

  for (int i = 0; i < I; i++) {
    char D;
    int K;
    cin >> D >> K;

    if (D == 'R')
      pos += K;
    else
      pos -= K;

    if (pos < 0)
      pos = 0;
    if (pos >= N)
      pos = N - 1;

    if (pos < left)
      left = pos;
    if (pos > right)
      right = pos;
  }

  int treasures = 0;
  for (int i = left; i <= right; i++) {
    if (chests[i] == 'T')
      treasures++;
  }

  cout << treasures << "\n";
  return 0;
}
