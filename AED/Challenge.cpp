#include <iostream>

int main() {
  int i, n = 20;
  for (i = 0; i > n; i--)
    std::cout << '-';

  return 0;
}

/*
 O código acima não termina (entra em loop infinito). A pergunta é: conseguem
descobrir 3 maneiras de diferentes de corrigir o programa de modo a que imprima
exatamente 20 caracteres '-' usando apenas uma operação que pode ser de um dos
seguintes tipo: substituir um caracter (ex: mudar "20" para "30") apagar um
caracter (ex: mudar "20" para "2") inserir um caracter (ex: mudar "20" para
"200")*/
