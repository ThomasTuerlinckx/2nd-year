#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct par {
  int pos;
  char which;
};

bool matches(char open, char close) {
  return (open == '(' && close == ')') || (open == '[' && close == ']') ||
         (open == '{' && close == '}');
}

string pairType(char c) {
  if (c == '(')
    return "()";
  if (c == '[')
    return "[]";
  return "{}";
}

int main() {
  stack<par> st;
  vector<pair<string, pair<int, int>>> result;
  string a;
  getline(cin, a);

  bool hasBrackets = false;

  for (int i = 0; i < (int)a.size(); i++) {
    char e = a[i];

    if (e == '(' || e == '[' || e == '{') {
      hasBrackets = true;
      st.push({i, e});
    } else if (e == ')' || e == ']' || e == '}') {
      hasBrackets = true;

      if (st.empty() || !matches(st.top().which, e)) {
        cout << "badly matched pairs\n";
        return 0;
      }

      result.push_back({pairType(st.top().which), {st.top().pos, i}});
      st.pop();
    }
  }

  if (!st.empty()) {
    cout << "badly matched pairs\n";
    return 0;
  }

  if (!hasBrackets) {
    cout << "no brides and grooms to marry\n";
    return 0;
  }

  for (auto &r : result) {
    cout << r.first << " " << r.second.first << " " << r.second.second << "\n";
  }

  return 0;
}
