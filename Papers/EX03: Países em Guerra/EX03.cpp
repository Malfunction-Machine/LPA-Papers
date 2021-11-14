/* 
 * Tarefa: Países em Guerra
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(n²) O código terá complexidade igual a complexidade do Dijkstra, já que será necessário acessar todas as horas entre as cidades
*/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <limits.h>

#define INF 1 << 25

// Matriz que guarda os valores entre as cidades
int matriz[100][100];

/*
 * Algoritmo para achar o menor caminho para se entregar a carta
 * @entrada int cidade_o referente a cidade de partida
 * @entrada int cidade_d referente a cidade de destino
 * @entrada int num_cidades referente ao numero total de cidades
 * @saida int referente ao menor horario possivel entre as cidades selecionadas
*/
int dijkstra(int cidade_o, int cidade_d, int num_cidades) {
    int menor_distancia, prox_cidade;
    int distancias[num_cidades];
    bool correlacao[num_cidades];

    for (int i = 1; i <= num_cidades; i++) {
        distancias[i] = INF;
        correlacao[i] = false;
    }

    distancias[cidade_o] = 0;

    for (int i = 1; i <= num_cidades; i++) {
        menor_distancia = INF;

        if (correlacao[cidade_d]) break;

        for (int j = 1; j <= num_cidades; j++) {
            if (distancias[j] < menor_distancia && !correlacao[j]) {
                menor_distancia = distancias[j];
                prox_cidade = j;
            }
        }

        if (menor_distancia == INF) break;

        correlacao[prox_cidade] = true;

        for (int j = 1; j <= num_cidades; j++) {
            if (menor_distancia + matriz[prox_cidade][j] < distancias[j]) {
                distancias[j] = menor_distancia + matriz[prox_cidade][j];

            }
        }
    }

    return distancias[cidade_d];
}

int main(int argc, char const *argv[]) {
    int num_cidades, num_acordos; 

    std::cin >> num_cidades >> num_acordos;

    //Condição de parada onde N = E = 0
    while(num_cidades + num_acordos != 0) {

        for (int i = 1; i <= num_cidades; i++) {
            for (int j = 1; j <= num_cidades; j++) {
                matriz[i][j] = INF;

            }
        }

        int cidade_x, cidade_y, horas;

        // Construcao do grafo e leitura das entradas
        for(int i = 0; i < num_acordos; i++) { 
            std::cin >> cidade_x >> cidade_y >> horas;
            
            matriz[cidade_x][cidade_y] = horas;

            if(matriz[cidade_y][cidade_x] != INF) {
                matriz[cidade_x][cidade_y] = matriz[cidade_y][cidade_x] = 0;

            }
        }

        int consultas;
        std::cin >> consultas;

        int cidade_o, cidade_d, resposta;

        for (int i = 0; i < consultas; i++) {
            std::cin >> cidade_o >> cidade_d;
            
            resposta = dijkstra(cidade_o, cidade_d, num_cidades);
            
            if(resposta == INF) {
                std::cout << "Nao e possivel entregar a carta" << std::endl;

            } else {
                std::cout << resposta << std::endl;

            }
        }

        std::cout << std::endl;
        std::cin >> num_cidades >> num_acordos;
    }
}
