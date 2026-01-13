#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;

  while (tests--) {
    int R, C;
    cin >> R >> C;

    vector<string> maze(R);
    for (int i = 0; i < R; i++) {
      cin >> maze[i];
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    vector<vector<int>> dist(R, vector<int>(C, -1));

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (maze[i][j] == 'P') {
          q.push({i, j});
          dist[i][j] = 0;
        }
      }
    }

    int answer = -1;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      if (maze[r][c] == 'T') {
        answer = dist[r][c];
        break;
      }

      for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
          if (maze[nr][nc] != '#' && dist[nr][nc] == -1) {
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
          }
        }
      }
    }

    cout << answer << "\n";
  }

  return 0;
}
