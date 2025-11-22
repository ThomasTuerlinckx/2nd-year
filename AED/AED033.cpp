#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int countWords(const std::string &text) {
  std::stringstream ss(text);
  std::string word;
  int count = 0;

  while (ss >> word) {
    count++;
  }

  return count;
}

int main() {

  list<string> children;
  string a = "Yellow Here";
  getline(cin, a);
  int count = countWords(a);
  int b = 0;
  cin >> b;
  string c = "Yellow There";
  for (int i = 0; i < b; i++) {
    cin >> c;
    children.push_back(c);
  }

  auto it = children.begin();

  while (children.size() > 1) {
    for (int i = 0; i < count - 1; i++) {
      it++;
      if (it == children.end()) {
        it = children.begin();
      }
    }
    cout << *it << endl;
    it = children.erase(it);
    if (it == children.end()) {
      it = children.begin();
    }
  }
  cout << children.front() << endl;
  return 0;
}
