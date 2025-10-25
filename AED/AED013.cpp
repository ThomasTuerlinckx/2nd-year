#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;

  cin >> N;
  vector<int> sequence(N);
  for (int i = 0; i < N; i++) {
    cin >> sequence[i];
  }

  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int A, B;
    cin >> A >> B;
    // Find first element >= A
    auto lower = lower_bound(sequence.begin(), sequence.end(), A);
    auto upper = upper_bound(sequence.begin(), sequence.end(), B);
    int count = upper - lower;

    cout << count << endl;
  }

  return 0;
}
