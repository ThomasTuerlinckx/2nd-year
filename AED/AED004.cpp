#include <iostream>
using namespace std;

void factorize(int n) {
  int m = n;
  cout << m << "=";

  bool first = true;
  for (int d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      if (!first)
        cout << "*";
      cout << d;
      first = false;
      n /= d;
    }
  }

  if (n > 1) {
    if (!first)
      cout << "*";
    cout << n;
  }

  cout << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x;
    cin >> x;
    factorize(x);
  }

  return 0;
}
