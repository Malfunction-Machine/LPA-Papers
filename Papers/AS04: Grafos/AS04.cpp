/* 
 * Tarefa: Grafos (Roteadores)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: ...
*/

#include <iostream>
#include <vector>
using namespace std;

/*
 *Função responsável por verificar a existência de subsequência no caso de teste
 *@entrada string o caso de teste e uma string contendo a querie  
 *@saida bool validando ou não a existência de subsequências
*/
int main(int argc, char const *argv[]) {
    int peso;
    int fios;
    int vetor_1;
    int vetor_2;
    int roteadores;
    int contador = 0;

    vector<pair<int,pair<int,int>>> edges_weights;

    scanf("%d %d", &roteadores, &fios);

    while(contador < fios) {
        scanf("%d %d %d",&vetor_1, &vetor_2, &peso);
        
        edges_weights.push_back(make_pair(peso, make_pair(vetor_1, vetor_2)));

        contador++;
    }
}   