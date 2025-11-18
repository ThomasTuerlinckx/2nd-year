#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void vectorPrint(vector<int> v) {
  v = {1, 2, 3, 4, 5};

  // Printing elements of vector
  for (auto i : v)
    cout << i << " ";
}

int main() {
  int N, num, Q;
  vector<int> v1;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    v1.push_back(num);
  }
  vector<int> v2;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> num;
    v2.push_back(num);
  }
  sort(v1.begin(), v1.end());

  int dif1, dif2;
  vector<int> v3;
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      break;
    } else {
      for (int j = i + 1; j < N - 1; j++) {
        num = v1[i] + v1[j];
        v3.push_back(num);
      }
    }
  }
  sort(v3.begin(), v3.end());
  for (auto i : v2) {

    auto it = lower_bound(v3.begin(), v3.end(), i);
    dif1 = abs(*it - i);
    dif2 = abs(*(it - 1) - i);
    cout << " v3- ";
    vectorPrint(v3);

    cout << " i- " << i << " it- " << *it << " dif1- " << dif1 << " dif2- "
         << dif2 << endl;
    if (dif1 > dif2)
      cout << *it << endl;
    else if (dif1 < dif2)
      cout << *(it - 1) << endl;
    else if (dif1 == dif2)
      cout << *it << " " << *(it - 1) << endl;
  }
  return 0;
}
