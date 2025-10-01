#include <iostream>
#include <cmath>
using namespace std;





void factorial(int a) {
	int i = 2;
	int count = 0;

		while(true){
		
		if (a==i){
		cout << i;
		break;
		}


		while (a % i == 0){
			cout << i << "*";
			a = a /i;
			
		}

		if (a%i != 0){
			i++;;
	
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

