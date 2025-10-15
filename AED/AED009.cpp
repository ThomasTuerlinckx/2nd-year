
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++)
    cin >> v[i];

  int returnable = -2000;
  int temp = 0;

  for (int i = 0; i < N; i++) {
    temp += v[i];
    if (temp > returnable)
      returnable = temp;
    if (temp < 0)
      temp = 0;
  }

  cout << returnable << endl;
  return 0;
}
