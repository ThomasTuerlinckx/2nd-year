#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Process {
  string name;
  int remaining;
};

int main() {
  int T, N;
  cin >> T >> N;

  queue<Process> q;

  for (int i = 0; i < N; i++) {
    Process p;
    cin >> p.name >> p.remaining;
    q.push(p);
  }

  int currentTime = 0;
  int iteration = 0;

  while (!q.empty()) {
    iteration++; // increment on **every time a process is picked**
    Process p = q.front();
    q.pop();

    int exec = min(T, p.remaining);
    currentTime += exec;
    p.remaining -= exec;

    if (p.remaining > 0) {
      q.push(p);
    } else {
      cout << p.name << " " << currentTime << " " << iteration << "\n";
    }
  }

  return 0;
}
