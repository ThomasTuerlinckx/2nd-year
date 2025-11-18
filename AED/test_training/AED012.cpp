#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, num, Q;
  vector<int> v;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }
  cin >> Q;
  int pos = 0;
  for (int i = 0; i < Q; i++) {

    cin >> num;
    if (num > v[N - 1]) {
      pos = -1;
    } else {
      auto up = lower_bound(v.begin(), v.end(), num);
      pos = up - v.begin();
    }
    cout << pos << endl;
  }

  return 0;
}
