#include <iostream>
#include <vector>
using namespace std;

int main() {

  int secions, study, depth;
  cin >> secions >> study >> depth;
  vector<int> v1;
  int tester = 0;
  study % 2 == 0 ? tester = study / 2 : tester = study / 2 + 1;

  int window = 0;
  int a;
  int count = 0;

  for (int i = 0; i < secions; i++) {
    cin >> a;
    v1.push_back(a);
  }

  for (int i = 0; i < study; i++) {

    if (v1[i] >= depth) {
      window += 1;
    }
  }
  if (window >= tester)
    count++;

  for (int i = study; i < secions; i++) {
    if (v1[i - study] >= depth) {
      window--;
    }
    if (v1[i] >= depth) {
      window++;
    }
    if (window >= tester) {
      count++;
    }
  }
  cout << count << endl;

  return 0;
}
