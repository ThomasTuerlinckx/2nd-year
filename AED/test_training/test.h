std::list<int> shortestPath(int a, int b) {
  //
  for (Node &n : nodes) {
    n.visited = false;
    n.cameFrom = -1;
  }
  std::queue<int> q;
  nodes[a].distance = 0;
  q.push(a);
  nodes[a].visited = true;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (Edge e : nodes[curr].adj) {
      int next = e.dest;
      if (!nodes[next].visited) {
        q.push(next);
        nodes[next].visited = true;
        nodes[next].distance = nodes[curr].distance + 1;
        nodes[next].cameFrom = curr;
      } else if (nodes[next].distance == nodes[curr].distance + 1) {
        if (nodes[next].cameFrom > curr) {
          nodes[next].cameFrom = curr;
        }
      }
    }
  }
  if (nodes[b].cameFrom == -1) {
    return std::list<int>();
  }
  std::list<int> order;
  int curr = b;
  for (int i = 0; i <= nodes[b].distance; i++) {
    order.push_front(curr);
    curr = nodes[curr].cameFrom;
  }
  return order;
}
