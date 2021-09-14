/* 
 * Tarefa: Componentes Conexos (Grafos)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: 
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
    int N;
    int V;
    int E;
    std::string teste;
    int contador = 1;

    scanf("%d",&N);

    while (contador <= N)
    {
        scanf("%d" "%d",&V ,&E);
        std::cin.ignore();

        for(int i = 0; i < E; i++) {
            
            std::getline(std::cin, teste);

        }

        std::cout << "Case #" << contador << ":" << std::endl;

        std::cout <<  teste << " connected components" << std::endl << std::endl;

        contador++;
    }
}   