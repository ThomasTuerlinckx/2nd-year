#include <iostream>
#include <cmath>
using namespace std;





void factorial(int a) {
	int i = 3;
	if (a %2 == 0){
		cout << 2 << "*";
	}

	while(i <= sqrt(a)){
		
		if (a==i){
		cout << i;
		}

		else if (a % i == 0){
			cout << i << "*";
			a = a /i;
		}

		else if (a%i != 0){
			i += 2;
	
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

