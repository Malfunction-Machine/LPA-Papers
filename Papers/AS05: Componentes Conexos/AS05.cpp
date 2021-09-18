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

class Graph {

};


int main(int argc, char const *argv[]) {
    int N;
    int V;
    int E;
    int contador = 1;
    std::string teste;

    scanf("%d",&N);

    std::vector<std::pair<int, char>> vertices;

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