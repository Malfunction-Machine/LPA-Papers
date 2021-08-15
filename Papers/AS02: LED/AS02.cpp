/* 
 * Tarefa: Strings (LED)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(N) -> Onde N é a quantidade de testes que serão realizadas durante a leitura da string
*/

#include <iostream>
using namespace std;

/*
 *Função responsável por calcular o número de LEDs necessarias 
 *@entrada string contendo o número à ser escrito com LEDs  
 *@saida int contendo o número de LEDs necessarios
*/
int contaLeds(string numero) {
    int leds = 0;
    int contador = 0;
    
    while (contador < numero.length()) {
        if(numero[contador] == '1') {
            leds += 2;
        } else if(numero[contador] == '4') {
            leds += 4;
        } else if(numero[contador] == '7') {
            leds += 3;
        } else if(numero[contador] == '8') {
            leds += 7;
        } else if(numero[contador] == '6' || numero[contador] == '9' || numero[contador] == '0') {
            leds += 6;
        } else {
            leds += 5;
        }

        contador++;
    }
    
    return leds;
}

int main(int argc, char const *argv[]) {
    int contador = 0;
    int entrada;
    string numero;

    scanf("%d",&entrada);

    while(contador < entrada) {
        std::cin >> numero;
        std::cout << contaLeds(numero) << " leds" << endl;
        contador++;
    }
}