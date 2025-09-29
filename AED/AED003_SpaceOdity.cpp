#include <iostream>
using namespace std;

void factorial(int a) {
    int cur_prime = 2;
    while (true) {
        if (a == cur_prime){
		cout << cur_prime;
		break;
	}

	if (a%cur_prime == 0){
		cout << cur_prime << "*";
		a = a/cur_prime;
	}

	if(a%cur_prime != 0){
		cur_prime++;
	}
    }
}

int main() {
    int loop;
    cin >> loop;

    for (int i = 0; i < loop; i++) {
        int a;
        cin >> a;
        cout << a << "=";
        factorial(a);
        cout << endl;
    }

    return 0;
}
