#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int inpu, number;
  vector<int> v;
  cin >> inpu;
  for (int i = 0; i < inpu; i++) {
    cin >> number;
    v.push_back(number);
  }
  int Q;
  cin >> Q;
  int pos = -1;
  int a = 0;
  for (int i = 0; i < Q; i++) {
    a = 0;
    cin >> number;
    auto lower = lower_bound(v.begin(), v.end(), number);
    a = lower - v.begin();

    if (lower == v.end() || *lower != number) {
      a = -1;
    }
    cout << a << endl;
  }

  return 0;
}
