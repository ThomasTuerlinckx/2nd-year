#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  int a = 0;
  string b = "hello world";
  vector<string> vecte;
  cin >> a;
  for (int i = 0; i <= a; i++) {
    getline(cin, b);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    sort(b.begin(), b.end());
    b.erase(remove_if(b.begin(), b.end(), ::isspace), b.end());

    vecte.push_back(b);
  }
  sort(vecte.begin(), vecte.end());

  int count = 0;
  string c = "hello world";

  for (size_t i = 0; i < vecte.size(); i++) {

    if (c != vecte[i]) {
      if (i != vecte.size() - 1) {
        if (vecte[i] == vecte[i + 1]) {
          count++;
        }
      }
      c = vecte[i];
    }
  }

  cout << count << endl;
  return 0;
}
