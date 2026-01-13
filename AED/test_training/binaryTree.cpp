#include "binaryTree.h"
#include <iostream>
#include <string>

int main() {
  BTree<int> t;

  // Read tree in preorder, using "N" as null
  // Example input: 1 2 N N 3 N N
  t.read("N");

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int s;
    std::cin >> s;

    std::cout << "pathFinder(\"" << s << "\") = " << t.pathFinder(s)
              << std::endl;
  }

  return 0;
}
