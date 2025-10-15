#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int countSetBits(int n) {
  int count = 0;

  // Runs till the n is greater than 0
  while (n) {

    // Check the least significant bit
    count += n & 1;

    // Right shift the number by 1
    n >>= 1;
  }
  return count;
}

bool compare(const int &a, const int &b) {
  int countA = countSetBits(a);
  int countB = countSetBits(b);

  if (countA == countB)
    return a < b;

  return countA > countB;
}

int main() {
  vector<int> v;

  int A = 0;
  int B;
  cin >> A;
  for (int i = 0; i < A; i++) {
    cin >> B;
    v.push_back(B);
  }

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < A; i++) {
    cout << v[i] << endl;
  }
  return 0;
}
