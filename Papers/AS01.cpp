#include <iostream>
#include <fstream>
#include <cstdlib>

int soma_fatorial(int x, int y) {
    return x + y;
}

int fatorial(int M) {
    int fatorial = 1;

    for (size_t i = M; i >= 2; i--)
    {
        fatorial *= i;
    }
    
    return fatorial;
}

int main() {
    const int TAM = 100;
    char entrada[TAM];
    int M;
    int N;

    while(fgets(entrada, TAM ,stdin))
    {
        std::cin >> M >> N;
        std::cout << soma_fatorial(fatorial(M),fatorial(N)) << std::endl;    
    } 
}