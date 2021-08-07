#include <iostream>
using namespace std;

//Função que retorna o fatorial do número enviado
unsigned long int fatorial(int numero) {
    unsigned long int fatorial = 1;

    for (int i = numero; i > 1; i--) {
        fatorial *= i;
    }
    
    return fatorial;
}

//Função que faz a soma dos fatoriais
int main(int argc, char const *argv[]) {
    int M;
    int N;

    while (scanf("%d %d", &M, &N) != EOF) {
        std::cout << (fatorial(M) + fatorial(N)) << std::endl;
    }
}