/* 
 * Tarefa: Componentes Conexos (Grafos)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(N²) onde N é a quantidade de vertices. A resolução se baseia em pecorrer todo 
 *                o grafo em todos os vertices. Ao realizar uma pesquisa, no pior dos casos, seria 
 *                necessário percorrer por cada um dos vertices, sendo um agravante impactante no 
 *                custo do algortimo.
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
        * Converter int para char
        * O valor do 'a' em ASCII na base decimal é 97, logo basta adicionar o valor do char por esse valor e converter o mesmo para char
        */ 
        char conversorIntChar(int numero) {
            return (char)(numero + 97); 
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
        std::vector<char> dfs(int vertice, std::vector<bool>* visitado) {

            visitado-> at(vertice) = true;

            std::vector<char> componente_conexo = { conversorIntChar(vertice) };

            auto vertices_adjacentes = this->lista_adj.at(vertice); 

            for (int i = 0 ; i < vertices_adjacentes.size(); i++)

                if (!visitado->at(vertices_adjacentes.at(i))) {

                    auto tmp = dfs(vertices_adjacentes.at(i), visitado);
                    for(int i = 0; i < tmp.size(); i++) {
                        char aux = tmp.at(i);
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

                    std::vector<char> vertices_ordenados = dfs(conta_vertices, &visitado);

                    std::sort(vertices_ordenados.begin(), vertices_ordenados.end());
                    
                    for(int i = 0; i < vertices_ordenados.size(); i++) {
                        
                        std::cout << vertices_ordenados.at(i) << ",";
                    }
                    
                    componentes++;
                    std::cout << std::endl; 
                }

                conta_vertices++;
            }

            visitado.clear();

            visitado.shrink_to_fit();

            return componentes;
        }
};

int main(int argc, char const *argv[]) {
    int N; // Numero de casos
    int V; // Numero de vertices
    int E; // Numero de arestas
    int conta_vertices = 1;

    scanf("%d",&N);

    while (conta_vertices <= N) {
        
        scanf("%d" "%d",&V ,&E);
        std::cin.ignore();
        
        Grafo* grafo = new Grafo(V);

        for(int i = 0; i < E; i++) {
            
            char vertice_1, vertice_2;

            std::cin >> vertice_1 >> vertice_2;

            grafo->add_aresta((int)vertice_1 - 97, (int)vertice_2 - 97);
        }

        std::cout << "Case #" << conta_vertices << ":" << std::endl;
        int count_componentes = grafo -> contaComponentes();
        std::cout << count_componentes << " connected components" << std::endl << std::endl;

        conta_vertices++;
        delete grafo;
    }
}   