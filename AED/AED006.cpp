#include <iostream>

using namespace std;

int main() {

  // Read Bakugans energy
  int n;
  cin >> n;
  int energy[n+1];
  int pre[n+2];
  pre[0] = 0;
  int var;
  for (int i=0; i<n; i++){
    cin >> var;
    energy[i] = var;
    pre[i+1] = pre[i] + var; 
}

  // Read and process photos

int fotos;
cin >> fotos;
for (int i= 0; i < fotos; i++){
  int primeiro, ultimo, resultado = 0;
  cin >> primeiro >> ultimo;
  resultado = pre[ultimo] - pre[primeiro-1];
  cout << resultado << endl;
}
  return 0;
  }