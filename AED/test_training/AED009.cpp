#include <algorithm>
#include <climits>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
  int a;
  cin >> a;
  vector<int> v(a);
  for (int i = 0; i < a; i++) {
    cin >> v[i];
  }
  int returnble = -2000;
  int temp = 0;

  for (int i = 0; i < a; i++) {
    temp += v[i];
    if (temp > returnble) {
      returnble = temp;
    }
    if (temp < 0) {
      temp = 0;
    }
  }

  cout << returnble << endl;
  return 0;
}
