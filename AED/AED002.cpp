#include <iostream>
using namespace std;

int remove(int a[], int n, int x) {
  int used = 0;
  int pos = 0;
  while (pos < n) {
    if (a[pos] != x) {
      a[used] = a[pos];
      used++;
    }
    pos++;
  }
  return used;
}

int main() {
  int N, X;
  cin >> N >> X;

  int a[100]; // N ≤ 100 (from problem constraints)
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  // filter out unlucky number
  int count = remove(a, N, X);

  // print count
  cout << count << "\n";

  // print remaining numbers
  for (int i = 0; i < count; i++) {
    if (i > 0)
      cout << " ";
    cout << a[i];
  }
  cout << "\n";

  return 0;
}
