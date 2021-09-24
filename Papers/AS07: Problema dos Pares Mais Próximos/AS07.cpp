/* 
 * Tarefa: Problema dos Pares Mais Próximos (Geometria Computacional)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(N²) Para encontrar todas as distancias entre os pontos e verificar
 *                qual delas será a menor distancia, é necessário passar por todo o vetor 
 *                duas vezes. Logo aumentado a complexidade do código.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

// Definindo 10000
#define INF 10000

/*
 * Calcula a distancia entre cada ponto
 * @entrada vetor de pair de (int,int) que pega a coordenada de x e y de cada ponto
 * @saida vetor de float armazenando todas as distancias entre os pontos
*/
std::vector<float> calculaDistancia(std::vector<std::pair<int,int>> pontos) {
    std::vector<float> distancias;

    for(int i = 0; i < pontos.size(); i++) {

        for(int j = i + 1; j < pontos.size(); j++) {

            distancias.push_back(sqrt(pow(pontos[i].first - pontos[j].first, 2) + pow(pontos[i].second - pontos[j].second, 2)));
        }
    }


    return distancias;
}

/*
 * Procura a menor distancia entre todas as distancias entre os pontos
 * @entrada vetor de float contendo todas as distancias entre os pontos
 * @saida float designado para armazenar a menor distancia entre dois pontos
*/
float menorDistancia(std::vector<float> distancias) {
    float menor_distancia = INF;

    for(int i = 0; i < distancias.size(); i++) {
        
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

    
    std::cin >> count_pontos;

    // Continua executando até o numero de pontos do conjunto ser igual a 0
    while (!count_pontos == 0) {
        
        std::vector<std::pair<int,int>> pontos; 
        std::vector<float> distancias;

        // Armazena os pontos em um vetor
        for(int i = 0; i < count_pontos; i++) { 
            std::cin >> cord_x >> cord_y;
            pontos.push_back(std::make_pair(cord_x, cord_y));
        }

        distancias = calculaDistancia(pontos);
        float menor_distancia = menorDistancia(distancias);

        // Verifica se a menor distancia é menor que 10000
        if(menor_distancia < INF) {
            std::cout << std::fixed << std::setprecision(4) << menor_distancia << std::endl;
        } else {
            std::cout << "INFINITY" << std::endl;
        }

        // Limpa os vetores para um novo teste
        pontos.clear();
        distancias.clear();

        std::cin >> count_pontos;    
    }
}   