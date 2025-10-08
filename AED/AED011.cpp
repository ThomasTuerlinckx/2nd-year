// AED 2025/2026 [Pedro Ribeiro - DCC/FCUP]
// Initial code for testing the times of linear search vs binary search

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#define PRECISION 6 // precision shown on time prints

using namespace std;

int bubble(const vector<int> &n, int target) {
  int left = 0;
  int right = n.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (n[mid] == target)
      return mid;
    else if (n[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}
int main() {
  int size;

  cin >> size;
  vector<int> list;
  for (int i = 0; i < size; i++) {
    int aa;
    cin >> aa;
    list.push_back(aa);
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int current;
    cin >> current;
    int response = bubble(list, current);
    cout << response << endl;
  }

  return 0;
}
