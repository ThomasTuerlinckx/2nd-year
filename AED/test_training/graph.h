// -------------------------------------------------------------
// Algorithms and Data Structures 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// A simple lightweight graph class
// Last update: 24/11/2024
// -------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

class Graph {
  struct Edge {
    int dest;   // Destination node
    int weight; // An integer weight
  };

  struct Node {
    std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    bool visited;
    int dist; // Has the node been visited in a graph traversal?
    bool passed;
    int previous = -1;
  };

  int n;                   // Graph size (vertices are numbered from 1 to n)
  bool hasDir;             // false: undirected; true: directed
  std::vector<Node> nodes; // The list of nodes being represented

public:
  // Constructor: nr nodes and direction (default: undirected)
  Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num + 1) {}

  // Add edge from source to destination with a certain weight
  void addEdge(int src, int dest, int weight = 1) {
    if (src < 1 || src > n || dest < 1 || dest > n)
      return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir)
      nodes[dest].adj.push_back({src, weight});
  }

  // --------------------------------------------------------------

  // Read a graph in the format:
  // nr_nodes directed/undirected weighted/unweighted
  // nr_edges
  // src_1 dest_1 <weight_1>
  // src_2 dest_2 <weight_2>
  // ...
  // src_n dest_n <weight_n>
  static Graph *readGraph() {
    int n;
    std::string sdirection, sweight;
    std::cin >> n >> sdirection >> sweight;
    bool directed = (sdirection == "directed") ? true : false;
    bool weighted = (sweight == "weighted") ? true : false;

    Graph *g = new Graph(n, directed);
    int e;
    std::cin >> e;
    for (int i = 0; i < e; i++) {
      int u, v, w = 1;
      std::cin >> u >> v;
      if (weighted)
        std::cin >> w;
      g->addEdge(u, v, w);
    }
    return g;
  }

  // --------------------------------------------------------------
  // Depth-First Search (DFS): example implementation
  // --------------------------------------------------------------
  void dfs(int v) {
    std::cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        dfs(w);
    }
  }

  // --------------------------------------------------------------
  // Breadth-First Search (BFS): example implementation
  // --------------------------------------------------------------
  void bfs(int v) {
    for (int i = 1; i <= n; i++)
      nodes[i].visited = false;
    std::queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unv;
      int u = q.front();
      q.pop();
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
          q.push(w);
          nodes[w].visited = true;
        }
      }
    }
  }

  // --------------------------------------------------------------

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------

  int distance(int a, int b) {

    for (int i = 1; i <= n; i++) {
      nodes[i].visited = false;
      nodes[i].dist = 0;
    }

    std::queue<int> q;
    q.push(a);
    nodes[a].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
      int u = q.front();
      q.pop();
      if (u == b) {
        return nodes[u].dist;
      }
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
          q.push(w);
          nodes[w].dist = nodes[u].dist + 1;
          nodes[w].visited = true;
        }
      }
    }
    return -1;
  }

  int diameter() {
    int diam = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j)
          continue;
        int d = distance(i, j);
        if (d == -1) {
          return -1;
        }
        if (d > diam)
          diam = d;
      }
    }
    return diam;
  }
  void PathBfs(int a, int b) {

    for (int i = 1; i <= n; i++) {
      nodes[i].adj.sort(
          [](const Edge &x, const Edge &y) { return x.dest < y.dest; });
    }

    for (int i = 1; i <= n; i++) {
      nodes[i].visited = false;
      nodes[i].previous = -1;
    }

    std::queue<int> q;
    q.push(a);
    nodes[a].visited = true;
    nodes[a].dist = 0;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto e : nodes[curr].adj) {
        int next = e.dest;
        if (!nodes[next].visited) {
          nodes[next].visited = true;
          nodes[next].dist = nodes[curr].dist + 1;
          nodes[next].previous = curr;
          q.push(next);
        } else if (nodes[next].dist == nodes[curr].dist + 1) {
          if (nodes[next].previous > curr) {
            nodes[next].previous = curr;
          }
        }
      }
    }
  }

  std::list<int> shortestPath(int a, int b) {
    std::list<int> l;
    PathBfs(a, b);

    if (!nodes[b].visited) {
      return l;
    }
    for (int v = b; v != -1; v = nodes[v].previous) {
      l.push_front(v);
      if (v == a)
        break;
    }
    return l;
  }
};

#endif
