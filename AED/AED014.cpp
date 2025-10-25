#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(const vector<int> &v, int x, int k) {
  int partitions = 1;
  int current_sum = 0;

  for (int distance : v) {
    if (distance > x) {
      return false;
    }

    if (current_sum + distance > x) {
      partitions++;
      current_sum = distance;

      if (partitions > k) {
        return false;
      }
    } else {
      current_sum += distance;
    }
  }

  return partitions <= k;
}

int findOptimalCost(const vector<int> &distances, int k) {
  int left = *max_element(distances.begin(), distances.end());
  int right = 0;
  for (int d : distances) {
    right += d;
  }

  int answer = right;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (isPossible(distances, mid, k)) {
      answer = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return answer;
}

int main() {
  int N;
  cin >> N;

  vector<int> distances(N);
  for (int i = 0; i < N; i++) {
    cin >> distances[i];
  }

  int Q;
  cin >> Q;

  vector<int> results(Q);
  for (int i = 0; i < Q; i++) {
    int Ki;
    cin >> Ki;
    results[i] = findOptimalCost(distances, Ki);
  }

  for (int result : results) {
    cout << result << endl;
  }

  return 0;
}
