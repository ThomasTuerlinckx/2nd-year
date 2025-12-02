#include <iostream>
#include <queue>

using namespace std;

struct Process {
  int time;
  string name;
};

int main() {
  queue<Process> q;
  int T, N;

  cin >> T >> N;

  Process help;
  for (int i = 0; i < N; i++) {
    cin >> help.name;
    cin >> help.time;
    q.push(help);
  }
  int currentTime = 0;
  int iterationCount = 0;

  while (!q.empty()) {
    iterationCount++;
    Process current = q.front();
    q.pop();

    if (current.time <= T) {
      // Process finishes in this iteration
      currentTime += current.time;
      cout << current.name << " " << currentTime << " " << iterationCount
           << endl;
    } else {
      // Process needs more time, put it back in queue
      currentTime += T;
      current.time -= T;
      q.push(current);
    }
  }

  return 0;
}
