#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  int N, Q, X, a;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a;
    v.push_back(a);
  }

  cin >> Q;

  int count = 0;
  for (int i = 0; i < Q; i++) {
    cin >> a;
    auto b = lower_bound(v.begin(), v.end(), a);

    int b_ = (b - v.begin());
    if (b_ >= N) {
      b_ = -1;
    }

    cout << (b_) << endl;
  }
  return 0;
}
