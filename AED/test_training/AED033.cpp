#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string.h>
using namespace std;
int stringCount(const std::string &text) {
  std::stringstream ss(text);
  std::string word;
  int count = 0;

  while (ss >> word) {
    count++;
  }

  return count;
}

int main() {
  list<string> l;
  string S;
  getline(cin, S);
  int num = stringCount(S);
  int a;
  cin >> a;
  string temp;
  for (int i = 0; i < a; i++) {
    cin >> temp;
    l.push_back(temp);
  }
  auto it = l.begin();
  int smaller = 0;
  while (l.size() > 0) {
    for (int i = 0; i < num - 1; i++) {
      ++it;
      if (it == l.end()) {
        it = l.begin();
      }
    }

    cout << *it << endl;
    it = l.erase(it);

    if (l.empty())
      break;
    if (it == l.end())
      it = l.begin();
  }

  return 0;
}
