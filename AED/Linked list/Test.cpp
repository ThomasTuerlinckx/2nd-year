#include "singlyLinkedList.h"
#include <iostream>
#include <vector>

using namespace std;

// Helper function to print test results
void printTestResult(const string& testName, bool passed) {
    cout << "[" << (passed ? "PASS" : "FAIL") << "] " << testName << endl;
}

int main() {
    cout << "==================================================" << endl;
    cout << "Testing SinglyLinkedList::sort() Function" << endl;
    cout << "==================================================" << endl << endl;

  

    // Test 5: Multiple elements (random order)
    
        cout << "Test 5: Multiple elements (random order)" << endl;
        SinglyLinkedList<int> list;
        list.addLast(5);
        list.addLast(2);
        list.addLast(8);
        list.addLast(1);
        list.addLast(9);
        cout << "Before sort: " << list.toString() << endl;
        list.sort();
        cout << "After sort:  " << list.toString() << endl;
        bool passed = list.toString() == "{1,2,5,8,9}";
        printTestResult("Random order is sorted correctly", passed);
        cout << endl;
    


    cout << "==================================================" << endl;
    cout << "All tests completed!" << endl;
    cout << "==================================================" << endl;

    return 0;
}
