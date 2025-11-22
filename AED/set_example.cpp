// AED 2025/2026 [Pedro Ribeiro - DCC/FCUP]
// An example usage of STL sets and multisets

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

  vector<int> v = {2, 4, 8, 3, 8, 2, 5, 4};

  set<int> s;
  multiset<int> ms;

  // Traverse all the values of the vector and insert them on set s and multiset
  // ms
  for (auto i : v) {
    s.insert(i);
    ms.insert(i);
  }

  // Print number of elements
  cout << "s.size() = " << s.size() << endl;
  cout << "ms.size() = " << ms.size() << endl;

  // Print the elements themselves (notice how they come in sorted order)
  cout << "s:";
  for (auto i : s)
    cout << " " << i;
  cout << endl;
  cout << "ms:";
  for (auto i : ms)
    cout << " " << i;
  cout << endl;

  // Normal forward iterator
  auto it = s.begin();
  cout << "it = s.begin(); it = " << *it << endl;
  it++;
  cout << "it++; it = " << *it << endl;
  it--;
  cout << "it--; it = " << *it << endl;
  it = s.end();
  it--;
  cout << "it = s.end(); it--; it = " << *it << endl;

  // Reverse iterator
  auto rit = s.rbegin();
  cout << "rit = s.rbegin(); rit = " << *rit << endl;
  rit++;
  cout << "rit++; rit = " << *rit << endl;

  // Checking if an element is on the set
  // find return an iterator to position or end() if not present
  cout << "is 5 on s? " << (s.find(5) != s.end() ? "yes" : "no") << endl;
  cout << "is 6 on s? " << (s.find(6) != s.end() ? "yes" : "no") << endl;

  // Erasing element by value
  s.erase(5);
  cout << "after removing 5, s.size() = " << s.size() << endl;
  cout << "after removing 5 again, s.size() = " << s.size() << endl;

  return 0;
}
