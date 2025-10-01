#include <iostream>
using namespace std;

int main() {
    int N, S, I;
    cin >> N >> S >> I;

    string chests;
    cin >> chests;

    int pos = S - 1;    
    int treasures = 0;

    if (chests[pos] == 'T') {
        treasures++;
        chests[pos] = 'E'; 
    }

    for (int i = 0; i < I; i++) {
        char D;
        int K;
        cin >> D >> K;

        int step = (D == 'R') ? 1 : -1;
        for (int j = 0; j < K; j++) {
            pos += step;
            if (chests[pos] == 'T') {
                treasures++;
                chests[pos] = 'E'; 
            }
        }
    }

    cout << treasures << "\n";
    return 0;
}

