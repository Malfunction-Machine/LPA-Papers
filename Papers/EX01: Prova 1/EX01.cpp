/* 
 * Tarefa: Prova Intermediária (Bactérias)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(N) -> Onde N é a quantidade de dias que serão analisados para descobrir o tamanho da nova colonia de bactérias
*/

#include <iostream>
using namespace std;

/*
 * Função responsável por realizar o calculo do tamanho da colonia no dia selecionado
 * @entrada int[] designado para armazenar a o numero de bacteris das colonias ao longo dos dias
 * @entrada int designado para daterminar o dia  
 * @saida int designado a quantidade de bacteris na colonia
*/
int calculaColonia(int bacterias[], int dia) {
    int colonia = 0;
    
    for(int i = 0; i < 4 ; i++) {
        colonia += bacterias[i];
    }

    for (int i = 4; i < dia; i++) {
        bacterias[i] = (colonia * 2) - bacterias[i - 4];
        colonia = bacterias[i];
    }
    
    return bacterias[dia - 1];
}


int main(int argc, char const *argv[]) {
    int dia;

    scanf("%d",&dia);

    // Aceita entradas até a mesma ser igual à zero
    while(dia != 0) {
        
        int bacterias[dia];

        scanf("%d %d %d %d", &bacterias[0], &bacterias[1], &bacterias[2], &bacterias[3]);

        cout << (calculaColonia(bacterias, dia) % 13371337) << endl;

        scanf("%d",&dia);
    }
} 