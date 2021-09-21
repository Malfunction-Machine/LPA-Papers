/* 
 * Tarefa: Roteadores (Grafos)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(A * log A + A * log V) onde A = aresta e V = vertice
 *                Essa complexidade se deve pelo fato de ordenarmos o vetor de vertices em
 *                ordem crescente com base no peso das arestas e por causa do custo do algoritmo
 *                de Kruskal
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
 * Classe DisjointSets 
*/
struct DisjointSets {

        int *rank, *parentesco;
        int tamanho;

    // Construtor da Classe
    DisjointSets(int tamanho) {

        this -> tamanho = tamanho;
        parentesco = new int[tamanho + 1];
        rank = new int[tamanho + 1];

        for (int i = 0; i <= tamanho; i++) {
            rank[i] = 0;
            parentesco[i] = i;
        }
    }

    // Encontra o parente do vetor selecionado
    int encontrar(int vetor_selecionado) {
        if(parentesco[vetor_selecionado] != vetor_selecionado) {
            parentesco[vetor_selecionado] = encontrar(parentesco[vetor_selecionado]);
        }
        return parentesco[vetor_selecionado];
    }

    // Faz união dos vetores com base no rank
    void merge(int vetor_1, int vetor_2) {
        int x = encontrar(vetor_1); 
        int y = encontrar(vetor_2);

        if(rank[x] > rank[y]) {
            parentesco[y] = x;
        } else if(rank[x] <= rank[y]) {
            parentesco[x] = y;
        } if(rank[x] == rank[y]) {
            rank[y]++;
        }

    }

};

/*
 *Função responsável por realizar o Algortimo de Kruskal
 *@entrada int designado para a quantidade de vertices
 *@entrada int designado para a quantidade de arestas  
 *@entrada vetor contendo três ints (um representando os pesos das arestas, dois ints selecionando os vetores disponiveis)
 *@saida int designado ao peso da Minimum Spanning Tree
*/
int kruskal(int roteadores, int fios, vector<pair<int,pair<int,int>>> peso_vertices) {
    
    int peso_mst = 0;
    
    // Ordena o vetor em ordem crescente com base no peso das arestas
    sort(peso_vertices.begin(),peso_vertices.end());

    // Realiza os DisjointSets dos vertices do grafo
    DisjointSets ds(roteadores);

    for(int i = 0; i < fios; i++) {
        
        int vetor_partida = peso_vertices[i].second.first;
        int vetor_chegada = peso_vertices[i].second.second;

        int set_vetor_partida = ds.encontrar(vetor_partida);
        int set_vetor_chegada = ds.encontrar(vetor_chegada);

        if(set_vetor_chegada != set_vetor_partida) {
            peso_mst += peso_vertices[i].first;
            ds.merge(vetor_partida,vetor_chegada);
        }
    }

    return peso_mst;
}

int main(int argc, char const *argv[]) {
    int peso;
    int fios;
    int vetor_1;
    int vetor_2;
    int roteadores;
    int contador = 0;

    vector<pair<int,pair<int,int>>> peso_vertices;

    // Ler os vertices e as arestas
    scanf("%d %d", &roteadores, &fios);

    // Construido o grafo com as entradas
    while(contador < fios) {
        scanf("%d %d %d",&vetor_1, &vetor_2, &peso);
        
        peso_vertices.push_back(make_pair(peso, make_pair(vetor_1, vetor_2)));

        contador++;
    }

    cout << kruskal(roteadores, fios, peso_vertices) << endl;
}   