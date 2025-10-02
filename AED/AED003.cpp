#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int countOdd = 0;
  int lastOdd = -1;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 != 0) {
      countOdd++;
      lastOdd = x;
    }
  }

  if (countOdd > 0) {
    cout << countOdd << " " << lastOdd << endl;
  } else {
    cout << 0 << " " << -1 << endl;
  }

  return 0;
}
