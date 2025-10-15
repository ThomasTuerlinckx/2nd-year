#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  int N = 0, K = 0;
  cin >> N >> K;
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < K; i++) {
    cout << v[N - i - 1] << endl;
  }
  return 0;
}
