#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {

  int C, num = 0, Q;
  set<int> s;
  cin >> C;
  for (int i = 0; i < C; i++) {
    cin >> num;
    s.insert(num);
  }

  cin >> Q;

  set<int> results;

  for (int i = 0; i < Q; i++) {
    cin >> num;
    if (s.find(num) == s.end()) {

      results.insert(num);
    }
  }
  cout << results.size() << endl;
  if (results.size() != 0) {
    bool first = true;
    for (int x : results) {
      if (!first)
        cout << " ";
      cout << x;
      first = false;
    }
    cout << endl;
  }

  return 0;
}
