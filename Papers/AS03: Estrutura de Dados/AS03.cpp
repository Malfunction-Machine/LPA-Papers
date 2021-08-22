/* 
 * Tarefa: Estrutura de Dados (Subsequências)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(N) -> Onde N é a quantidade de testes que serão realizadas durante os testes realizados para cada char
*/

#include <iostream>
using namespace std;

/*
 *Função responsável por verificar a existência de subsequência no caso de teste
 *@entrada string o caso de teste e uma string contendo a querie  
 *@saida bool validando ou não a existência de subsequências
*/
bool buscaSubsequencia(string sequencia, string querie) {
    bool encontrar = false;
    int contador = 0;

    for(int i = 0; i < sequencia.length() && encontrar == false; i++){
        if(sequencia[i] == querie[contador]) {
            contador++;
        }
        if(contador == querie.length()) {
            encontrar = true;
        }
    }
        
    return encontrar;
}

int main(int argc, char const *argv[]) {
    int contador = 0;
    int entrada;
    int count_queries;

    scanf("%d",&entrada);

    string sequencias[entrada];
    getline(std::cin, sequencias[contador]);

    while(contador < entrada) {
        getline(std::cin, sequencias[contador]);
        contador++;     
    }

    contador = 0;
    scanf("%d",&count_queries);
    string queries[count_queries];
    getline(std::cin, queries[contador]);


    while(contador < count_queries) {
        getline(std::cin, queries[contador]);
        contador++;  
    }

    for(int i = 0; i < entrada; i++) {
        for (int j = 0; j < count_queries; j++) {
            if (buscaSubsequencia(sequencias[i],queries[j])) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }   

}