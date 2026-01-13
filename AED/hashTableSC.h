// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// A simple lightweight implemetation of hash tables
// (using separate chaining, a.k.a. open hashing)
// Last update: 08/12/2024
// -------------------------------------------------------------

#ifndef _HASHTABLESC_H_
#define _HASHTABLESC_H_

#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

template <class KeyType> class HashTableSC {
  int size;                              // Size of the hash table
  int numberKeys;                        // Number of inserted keys
  std::vector<std::list<KeyType>> table; // The hash table itself
  std::function<unsigned(const KeyType &)>
      hash; // Hash function: key -> unsigned

public:
  // Constructor: receives the table size n and the hash function h
  HashTableSC(int n, std::function<unsigned(const KeyType &)> h)
      : size(n), numberKeys(0), table(n), hash(h) {}

  // Show contents of hash table (to check if implementation is correct)
  void showContents() {
    std::cout << "Size: " << size << " | Number of keys: " << numberKeys
              << " | Load Factor: " << std::fixed << std::setprecision(3)
              << (double)numberKeys / size << std::endl;
    for (int i = 0; i < size; i++) {
      std::cout << i << ":";
      if (table[i].size() == 0)
        std::cout << " EMPTY";
      else
        for (auto it : table[i])
          std::cout << " " << it;
      std::cout << std::endl;
    }
  }

  // ---------------------------------------------------------
  // TO DO: functions to implement in this exercise
  // ---------------------------------------------------------

  // Does it contain key k?

  // Insert key k (true if successful)
  bool insert(const KeyType &k) {
    int pos = hash(k) % size;
    auto it = find(table[pos].begin(), table[pos].end(), k);
    if (it != table[pos].end()) {
      return false;
    }
    table[pos].push_back(k);
    numberKeys++;
    return true;
  }
  bool contains(const KeyType &k) {
    int pos = hash(k) % size;
    auto it = find(table[pos].begin(), table[pos].end(), k);
    return it != table[pos].end();
  }

  bool remove(const KeyType &k) {
    int pos = hash(k) % size;
    auto it = find(table[pos].begin(), table[pos].end(), k);
    if (it == table[pos].end())
      return false;
    table[pos].erase(it);
    numberKeys--;
    return true;
  }

  // Remove key k (true if successful)
};

#endif
