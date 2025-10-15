// AED 2025/2026 [Pedro Ribeiro - DCC/FCUP]
// An example usage of the function 'sort'

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Example vector
  vector<int> v = {33, 4, 28, 18, 15, 2, 8, 17, 42, 39};

  cout << "Before sorting: ";
  for (int i = 0; i < 10; i++)
    cout << v[i] << " ";
  cout << endl;

  // Call to standard sort algorithm in C++
  // sort(RandomIterator start, RandomIterator end)
  sort(v.begin(), v.end());

  cout << " After sorting: ";
  for (int i = 0; i < 10; i++)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}
