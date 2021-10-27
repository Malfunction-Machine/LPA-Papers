/*
* Tarefa: Maçãs (Programação Dinâmica)
* Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
* Nome: Thiago Henriques Nogueira
* Matricula: 655085
* Professor: Wladmir Cardoso Brandão
* Complexiadade: O(n * m) onde n é a quantidade de macas derrubadas e m são todas as 
                 posições adjacentes a posição atual de Rafael. Basta lembrar que Rafael
                 ira se mover pelo cmapo, sendo necessario sempre recalcular as posições adjacentes
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>    
#include <vector>

// Classe contendo as informações da maca
class Maca {

    public:

    int coordenada_x;
    int coordenada_y;
    int tempo;
    int quantidade;

    Maca() {
        coordenada_x = 0;
        coordenada_y = 0;
        tempo = 0;
        quantidade = 0;
    }
};

/*
 * Função responsavel por imprimir a quanidade de maçãs
 * @entrada ponteiro de vector da classe Maca que armazena as cooredenadas, o tempo e a quantidade de macas
*/
void imprimiQuantidade(std::vector<Maca>* vetor) {
    std::cout << vetor->at(0).quantidade - 1 << std::endl;
}

/*
 * Função responsavel por retornar a maior distancia entre dois pontos
 * @entrada int que representa a distancia no eixo x 
 * @entrada int que representa a distancia no eixo y 
 * @saida int que representa a distancia maxima entre dois pontos
*/
int maxima (int distancia_x, int distancia_y) {
    if (distancia_x > distancia_y) {
        return distancia_x;
    }

    return distancia_y;
}

/*
 * Função responsavel por vericar se é possivel percorrer dois pontos em um determinado intervalo de tempo
 * @entrada ponteiro de vector da classe Maca que armazena as cooredenadas, o tempo e a quantidade de macas
 * @entrada int que representa a posição 
 * @entrada int que representa as posições adjacentes
 * @saida bool que representa se a distancia é possível de ser percorrida em determinado tempo
*/
bool distanciaMacas (std::vector<Maca>* vetor, int i, int j) {
    int distancia_x = abs(vetor->at(i).coordenada_x - vetor->at(j).coordenada_x);
    int distancia_y = abs(vetor->at(i).coordenada_y - vetor->at(j).coordenada_y);
    int distancia_pontos = maxima(distancia_x, distancia_y);
    int tempo_pontos = vetor->at(j).tempo - vetor->at(i).tempo;

    if (distancia_pontos <= tempo_pontos) {
        return true;
    }

    return false;
}

/*
 * Função responsavel por calcular a quantidade de macas que podem ser recolhidas em determinado tempo
 * @entrada int que armazena a quantidade de maçãs derrubadas
 * @entrada ponteiro de vector da classe Maca que armazena as cooredenadas, o tempo e a quantidade de macas
*/
void calculaQuantidade(int macas_derrubadas, std::vector<Maca>* vetor) {
    int distanciaMaxima, posicao;

    for (int i = macas_derrubadas; i >= 0; i--) {
        posicao = i;

        if(posicao >= vetor->size())
            continue;

        vetor->at(posicao).quantidade = 1;

        distanciaMaxima = 0;
        for(int j = (posicao+1); j <= macas_derrubadas; j++) {
            if(j >= vetor->size())
                continue;
            if (distanciaMacas(vetor, posicao, j) && vetor->at(j).quantidade > distanciaMaxima) {
                distanciaMaxima = vetor->at(j).quantidade;
            }
        }

        if (distanciaMaxima != 0) {
            vetor->at(posicao).quantidade = 1 + distanciaMaxima;
        }
    }

    imprimiQuantidade(vetor);

}

int main () {
 	int linhas = 0, colunas = 0, macas_derrubadas = 0;

    std::cin >> linhas >> colunas >> macas_derrubadas;
 	
    while (linhas != 0 && colunas != 0 && macas_derrubadas != 0) {

        std::vector<Maca> vetor(linhas*colunas*macas_derrubadas);
        
		for (int i = 1; i <= macas_derrubadas; i++) {
            std::cin >> vetor[i].coordenada_x>> vetor[i].coordenada_y >> vetor[i].tempo;
            
		}

        std::cin >> vetor[0].coordenada_x >> vetor[0].coordenada_y;
		vetor[0].tempo = 0;

        calculaQuantidade(macas_derrubadas,&vetor);

        std::cin >> linhas >> colunas >> macas_derrubadas;
	}
}
