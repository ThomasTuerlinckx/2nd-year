#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct PairInfo {
  char type; // '(' '[' '{'
  int openPos;
  int closePos;
};

bool isOpening(char c) { return c == '(' || c == '[' || c == '{'; }

bool isClosing(char c) { return c == ')' || c == ']' || c == '}'; }

bool matches(char open, char close) {
  return (open == '(' && close == ')') || (open == '[' && close == ']') ||
         (open == '{' && close == '}');
}

int main() {
  string E;
  getline(cin, E);

  stack<pair<char, int>> st; // char + position
  vector<PairInfo> result;   // store pairs in order of closure

  bool foundAny = false;

  for (int i = 0; i < (int)E.size(); i++) {
    char c = E[i];

    if (isOpening(c)) {
      foundAny = true;
      st.push({c, i});
    } else if (isClosing(c)) {
      foundAny = true;

      if (st.empty()) {
        cout << "badly matched pairs";
        return 0;
      }

      auto top = st.top();
      st.pop();

      if (!matches(top.first, c)) {
        cout << "badly matched pairs";
        return 0;
      }

      // Store the found pair
      result.push_back({top.first, top.second, i});
    }
  }

  // After processing everything
  if (!st.empty()) {
    cout << "badly matched pairs";
    return 0;
  }

  if (!foundAny) {
    cout << "no brides and grooms to marry";
    return 0;
  }

  // Print pairs in closure order (already in closure order)
  for (auto &p : result) {
    cout << p.type;
    if (p.type == '(')
      cout << ")";
    else if (p.type == '[')
      cout << "]";
    else
      cout << "}";

    cout << " " << p.openPos << " " << p.closePos << "\n";
  }

  return 0;
}
