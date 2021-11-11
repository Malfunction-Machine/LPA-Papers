/* 
 * Tarefa: Expensive Subway
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(N²) onde N é o número de buscas realizados pelo algortimo de Kruskal para se encontrar a MST 
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Grafo {

    private:

        // Verices e Arestas do grafo
        int vertices;
        int arestas;

        // Lista de adjacencia destinada a relacionar as ligações dos vertices
        std::vector<std::vector<int>> lista_adj;

    public:

    /* 
        * Construtor da classe Graph
        * @entrada int desiganado para o número de vertices do grafo
    */
    Grafo(int vertices) {
        this -> arestas  = 0;
        this -> vertices = 0;

        for(int i = 0; i < vertices; i++) {
            add_vertice();
        }
    }

    /* 
        * Adicionar novo vertice no grafo (incrementando os vertices dentro da classe Grafo)
        * Adicionar nova lista de adjacencia
    */
    void add_vertice() {

        this->vertices++;
        std::vector<int> lista_point;
        this -> lista_adj.push_back(lista_point);
    }

    /*
        * Adicionar aresta ao grafo
        * @entrada int designado para o vertice de partida
        * @entrada int designado para o vertice de chegada
    */
    void add_aresta(int vertice_inicial, int vertice_final) {
        
        if(vertice_inicial < this -> vertices && vertice_final < this -> vertices) {
            
            add_ListaAdj(vertice_inicial, vertice_final);
            add_ListaAdj(vertice_final, vertice_inicial);
            this->arestas++;
        }
    }

    /* 
        * Adicionar e relacionar os vértices a lista de adjacência
        * @entrada int designado para o vertice de partida
        * @entrada int designado para o vertice de chegada
    */
    void add_ListaAdj(int vertice_inicial, int vertice_final) {
        
        std::vector<int, std::allocator<int>>* lista_point = &this->lista_adj.at(vertice_inicial); 
        lista_point->push_back(vertice_final);            
    }

    /* 
        * Realiza uma 'depth vertice_inicial search' a fim de encontrar todos os vertices que estão ligados
        * @saida vetor de char contendo todos os vertices que formam um componente conexo
        * Descrição: Ao visitar um vertice, ela marca ele como visitado, logo após se pega os vizinhos desse vertice
        * Após disso seria necessário atravessar todos os vizinhos do vertice selecionado. gerando um vetor de char com o componente conexo
    */
    std::vector<int> dfs(int vertice, std::vector<bool>* visitado) {

        visitado-> at(vertice) = true;

        std::vector<int> componente_conexo;

        auto vertices_adjacentes = this->lista_adj.at(vertice); 

        for (int i = 0 ; i < vertices_adjacentes.size(); i++)

            if (!visitado->at(vertices_adjacentes.at(i))) {

                auto tmp = dfs(vertices_adjacentes.at(i), visitado);
                for(int i = 0; i < tmp.size(); i++) {
                    int aux = tmp.at(i);
                    componente_conexo.push_back(aux);
                }
            }

        return componente_conexo;
    }

    /*
        * Realiza contagem dos componentes conexos do grafo
        * @saida int designado para armazenar a quantidade de componentes conexos
        * Descrição: Realiza uma "depth first search" para encontrar os componentes complexos
        * e logo depois realiza um sort para ordenar os vertices
    */
    int contaComponentes() {

        int componentes = 0; 

        std::vector<bool> visitado(this->vertices, false);

        int conta_vertices = 0;

        while (conta_vertices < this->vertices) {
            
            if (visitado[conta_vertices] == false) {

                std::vector<int> vertices_ordenados = dfs(conta_vertices, &visitado);
                componentes++;
            }

            conta_vertices++;
        }

        visitado.clear();

        visitado.shrink_to_fit();

        return componentes;
    }
};

/*
* Pega o Index da estação com base na lista dos nomes das estações
* @saida int designado para armazenar o Index da estação
*/
int pegaIndex(std::string estacao, std::string nome_estacao[], int num_estacao) {
    int index;

    for(int i = 0; i < num_estacao; i++) {
        if(nome_estacao[i] == estacao)
            index = i; 
    }

    return index;
}

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
    void merge(int estacao_1, int estacao_2) {
        int x = encontrar(estacao_1); 
        int y = encontrar(estacao_2);

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
int kruskal(int num_estacoes, int num_conecxoes, std::vector<std::pair<int,std::pair<std::string,std::string>>> conexoes_estacoes, std::string nome_estacao[]) {
    
    int peso_mst = 0;
    
    // Ordena o vetor em ordem crescente com base no peso das arestas
    sort(conexoes_estacoes.begin(),conexoes_estacoes.end());

    // Realiza os DisjointSets dos vertices do grafo
    DisjointSets ds(num_estacoes);

    for(int i = 0; i < num_conecxoes; i++) {
        
        int vetor_partida = pegaIndex(conexoes_estacoes[i].second.first, nome_estacao, num_estacoes);
        int vetor_chegada = pegaIndex(conexoes_estacoes[i].second.second, nome_estacao, num_estacoes);

        int set_vetor_partida = ds.encontrar(vetor_partida);
        int set_vetor_chegada = ds.encontrar(vetor_chegada);

        if(set_vetor_chegada != set_vetor_partida) {
            peso_mst += conexoes_estacoes[i].first;
            ds.merge(vetor_partida,vetor_chegada);
        }
    }

    return peso_mst;
}

int main(int argc, char const *argv[]) {
    int num_estacoes; 
    int num_conexoes; 
    std::string estacao_inicial;
    
    std::cin >> num_estacoes >> num_conexoes;
    
    while (num_estacoes != 0 || num_conexoes != 0) {

        Grafo *grafo = new Grafo(num_estacoes);    
        std::vector<std::pair<int, std::pair<std::string,std::string>>> conexoes_estacoes;
        std::string nome_estacao[num_estacoes];

        // Lendo os nomes das estações  
        for (int i = 0; i < num_estacoes; i++) {
            std::cin >> nome_estacao[i];
            
        }

        // Lendo as conecxoes das estações e seus preços, armazenando os mesmos em um grafo 
        for(int i = 0; i < num_conexoes; i++) {
            int preco;
            
            std::string estacao_1, estacao_2;

            std::cin >> estacao_1 >> estacao_2 >> preco;

            conexoes_estacoes.push_back(make_pair(preco, make_pair(estacao_1, estacao_2)));
            grafo -> add_aresta(pegaIndex(estacao_1, nome_estacao, num_estacoes),pegaIndex(estacao_2, nome_estacao, num_estacoes));
        }

        std::cin >> estacao_inicial;
        
        if(grafo -> contaComponentes() < 2) {
            std::cout << kruskal(num_estacoes, num_conexoes, conexoes_estacoes, nome_estacao) << std::endl;

        } else {
            std::cout << "Impossible" << std::endl;

        }

        // Limpa a mémoria
        conexoes_estacoes.clear();
        delete(grafo);

        std::cin >> num_estacoes >> num_conexoes;
    }
}   