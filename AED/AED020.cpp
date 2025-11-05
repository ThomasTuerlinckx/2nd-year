#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int main() {
  int Student, initial = 0, final = 0;
  vector<int> Enteries;
  vector<int> Exits;
  int a, b;
  cin >> Student;
  for (int i = 0; i < Student; i++) {
    cin >> a;
    cin >> b;
    Enteries.push_back(a);
    Exits.push_back(b);
  }
  int max = 0;
  int current = 0;
  sort(Enteries.begin(), Enteries.end());
  sort(Exits.begin(), Exits.end());

  a = 0;
  b = 0;

  while (a < Student and b < Student) {
    if (Enteries[a] < Exits[b]) {
      current++;
      a++;
    } else {
      current--;
      b++;
    }

    if (max < current) {
      max = current;
    }
  }
  cout << max << endl;
  return 0;
}
