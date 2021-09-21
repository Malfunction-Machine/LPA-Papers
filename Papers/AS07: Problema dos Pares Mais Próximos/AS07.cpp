/* 
 * Tarefa: Problema dos Pares Mais Próximos (Grafos)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(A * log A + A * log V) onde A = aresta e V = vertice
 *                Essa complexidade se deve pelo fato de ordenarmos o vetor de vertices em
 *                ordem crescente com base no peso das arestas e por causa do custo do algoritmo
 *                de Kruskal
*/

#include <vector>
#include <cmath>
#include <bits/stdc++.h>

std::vector<float> calculaDistancia(std::vector<std::pair<int,int>> pontos) {
    std::vector<float> distancias;

    for(int i = 0; i < pontos.size(); i++) {

        for(int j = i + 1; j < pontos.size(); j++) {

            distancias.push_back(sqrt(pow(pontos[i].first - pontos[j].first, 2) + pow(pontos[i].second - pontos[j].second, 2)));
        }
    }


    return distancias;
}

float menorDistancia(std::vector<float> distancias) {
    float menor_distancia = distancias[0];

    for(int i = 1; i < distancias.size(); i++) {
        
        if(menor_distancia > distancias[i]) {
            menor_distancia = distancias[i];
        }

    }

    return menor_distancia;
}

int main(int argc, char const *argv[]) {
    int count_pontos;
    int cord_x;
    int cord_y;

    scanf("%d",&count_pontos);

    while (!count_pontos == 0) {
        std::vector<std::pair<int,int>> pontos; 
        
        for(int i = 0; i < count_pontos; i++) {
            scanf("%d %d", &cord_x, &cord_y);
            pontos.push_back(std::make_pair(cord_x, cord_y));
        }

        std::vector<float> distancias = calculaDistancia(pontos);
        float menor_distancia = menorDistancia(distancias);

        if(menor_distancia < 10000) {
            std::cout << menor_distancia << std::endl;
        } else {
            std::cout << "INFINITY" << std::endl;
        }

        pontos.clear();
        distancias.clear();

        scanf("%d",&count_pontos);
    }
}   