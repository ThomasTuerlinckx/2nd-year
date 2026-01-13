// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// Binary Tree
// Last update: 08/11/2025
// -------------------------------------------------------------

#ifndef BTREE_H
#define BTREE_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

template <class T> class BTree {
private:
  struct Node {
    T value;            // The value stored on the node
    Node *left, *right; // Pointers to left and right child
  };

  // The tree
  Node *root; // Pointer to the root node

public:
  // Constructor: initially the tree is empty
  BTree() { root = nullptr; }

  // Destructor: delete all nodes (garbage collection) [see slide 33]
  ~BTree() { destroy(root); }

  // Recursively delete left and right subtrees and then current node
  void destroy(Node *n) {
    if (n == nullptr)
      return;
    destroy(n->left);
    destroy(n->right);
    delete n;
  }

  // ---------------------------------------------------------
  // Count the number of nodes (see slides 11 and 12)
  // ---------------------------------------------------------

  int numberNodes() { return numberNodes(root); }

  int numberNodes(Node *n) {
    if (n == nullptr)
      return 0;
    return 1 + numberNodes(n->left) + numberNodes(n->right);
  }

  // ---------------------------------------------------------
  // Height of the tree (see slides 13 and 14)
  // ---------------------------------------------------------

  int height() { return height(root); }

  int height(Node *n) {
    if (n == nullptr)
      return -1;
    return 1 + std::max(height(n->left), height(n->right));
  }

  // ---------------------------------------------------------
  // Does the tree contain value 'val'? (see slides 15 and 16)
  // ---------------------------------------------------------

  bool contains(const T &val) { return contains(root, val); }

  bool contains(Node *n, const T &val) {
    if (n == nullptr)
      return false;
    if (n->value == val)
      return true;
    return contains(n->left, val) || contains(n->right, val);
  }

  // ---------------------------------------------------------
  // Print tree in PreOrder (see slides 18 and 19)
  // ---------------------------------------------------------

  void printPreOrder() {
    std::cout << "PreOrder:";
    printPreOrder(root);
    std::cout << std::endl;
  }

  void printPreOrder(Node *n) {
    if (n == nullptr)
      return;
    std::cout << " " << n->value;
    printPreOrder(n->left);
    printPreOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in InOrder (see slides 20 and 21)
  // ---------------------------------------------------------

  void printInOrder() {
    std::cout << "InOrder:";
    printInOrder(root);
    std::cout << std::endl;
  }

  void printInOrder(Node *n) {
    if (n == nullptr)
      return;
    printInOrder(n->left);
    std::cout << " " << n->value;
    printInOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in PostOrder (see slides 20 and 22)
  // ---------------------------------------------------------

  void printPostOrder() {
    std::cout << "PostOrder:";
    printPostOrder(root);
    std::cout << std::endl;
  }

  void printPostOrder(Node *n) {
    if (n == nullptr)
      return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    std::cout << " " << n->value;
  }

  // ---------------------------------------------------------
  // Print tree in Breadt-First order using a queue
  // (see slides 23, 24 and 25)
  // ---------------------------------------------------------

  void printBFS() {
    std::cout << "BFS:";

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *cur = q.front();
      q.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        q.push(cur->left);
        q.push(cur->right);
      }
    }

    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Print tree in Depth-First order using a stack
  // (see slides 26 and 27)
  // ---------------------------------------------------------

  void printDFS() {
    std::cout << "DFS:";

    std::stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
      Node *cur = s.top();
      s.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        s.push(cur->left);
        s.push(cur->right);
      }
    }

    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Read a tree in PreOrder from standard input
  // (see slides 28, 29 and 30)
  // ---------------------------------------------------------

  void read(std::string null) { root = readNode(null); }

  Node *readNode(std::string null) {
    std::string buffer;
    std::cin >> buffer;
    if (buffer == null)
      return nullptr;
    Node *n = new Node;
    std::istringstream ss(buffer);
    ss >> n->value;
    n->left = readNode(null);
    n->right = readNode(null);
    return n;
  }

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------
  //

  int numberLeafs() { return numberLeafs(root); }

  int numberLeafs(Node *n) {
    if (n == nullptr)
      return 0;
    if (n->left == nullptr && n->right == nullptr)
      return 1;
    return (numberLeafs(n->left) + numberLeafs(n->right));
  }

  bool strict(Node *n) {
    if (n == nullptr)
      return true;
    if ((n->left == nullptr && n->right != nullptr) ||
        (n->left != nullptr && n->right == nullptr))
      return false;
    return strict(n->left) && strict(n->right);
  }
  bool strict() { return strict(root); }

  T &path(std::string s) {
    Node *cur = root;

    if (s == "_")
      return cur->value;
    for (char c : s) {
      if (c == 'L')
        cur = cur->left;
      else if (c == 'R')
        cur = cur->right;
    }

    return cur->value;
  }
  int nodesLevel(int k) { return nodesLevel(root, 0, k); }
  int nodesLevel(Node *n, int level, int k) {
    if (n == nullptr)
      return 0;
    if (level == k)
      return 1;
    return nodesLevel(n->left, level + 1, k) +
           nodesLevel(n->right, level + 1, k);
  }

  int counterEven(Node *n) {
    if (n == nullptr)
      return 0;

    if (n->left == nullptr && n->right == nullptr) {
      if (n->value % 2 == 0) {
        return 1;
      }
    }
    if (n->value % 2 == 0) {
      return 1 + counterEven(n->right) + counterEven(n->left);
    }
    return counterEven(n->right) + counterEven(n->left);
  }

  int countEven() {
    Node *n = root;
    return counterEven(n);
  }

  /*
    int nodesSumLevel(Node *n, int level, int k) {
      if (n == nullptr)
        return 0;
      if (level == k)
        return n->value;
    */

  int max(int a, int b) {
    if (a >= b) {
      return a;
    } else
      return b;
  }

  struct bloody {
    int maxi;
    std::string pathy;
  };

  bloody Helper(Node *n) {
    if (n == nullptr) {
      return {0, ""};
    }

    if (n->left == nullptr && n->right == nullptr) {
      return {n->value, ""};
    }

    if (n->left == nullptr) {
      bloody r = Helper(n->right);
      return {n->value + r.maxi, "R" + r.pathy};
    }

    if (n->right == nullptr) {
      bloody l = Helper(n->left);
      return {n->value + l.maxi, "L" + l.pathy};
    }

    bloody r = Helper(n->right);
    bloody l = Helper(n->left);

    if (r.maxi >= l.maxi) {
      return {n->value + r.maxi, "R" + r.pathy};
    } else {
      return {n->value + l.maxi, "L" + l.pathy};
    }
  }

  std::string maxSum() {
    bloody pain = Helper(root);

    std::string a = pain.pathy;
    return a;
  }

  void genLR(int n, std::string &cur, std::vector<std::string> &res) {
    if ((int)cur.size() == n) {
      res.push_back(cur);
      return;
    }

    cur.push_back('L');
    genLR(n, cur, res);
    cur.back() = 'R';
    genLR(n, cur, res);
    cur.pop_back();
  }

  std::vector<std::string> genLRVector(int n) {
    std::vector<std::string> res;
    std::string cur;
    genLR(n, cur, res);
    return res;
  }

  std::string path2(const std::string &s) {
    Node *cur = root;
    std::string res;

    if (cur == nullptr)
      return res;

    res += std::to_string(cur->value);

    if (s == "_")
      return res;

    for (char c : s) {
      if (c == 'L')
        cur = cur->left;
      else if (c == 'R')
        cur = cur->right;
      res += " " + std::to_string(cur->value);
    }
    return res;
  }

  std::string pathFinder(int i) {
    int a = height();
    if (i == root->value)
      return "root";
    for (int len = 1; len <= i; ++len) {
      std::vector<std::string> vec = genLRVector(len);
      for (auto &p : vec) {
        if (path(p) == i) {
          return path2(p);
        }
      }
    }

    return "error";
  }
};

#endif
