/* 
 * Tarefa: Estrutura de Dados (Subsequências)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O(N) -> Onde N é a quantidade de caracteres testados que serão realizadas durante a validação realizados para cada char
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

    //Verifica char por char no intuito de descobrir a existência de subsequências
    for(int i = 0; i < sequencia.length() && encontrar == false; i++) {
        
        if(sequencia[i] == querie[contador]) {
            contador++;
        }
        
        //Caso a subsequencia pertença ao caso de teste
        if(contador == querie.length()) {
            encontrar = true;
        }
    }
        
    return encontrar;
}

int main(int argc, char const *argv[]) {
    int count_sequencias = 0;
    int count_queries = 0;
    int contador;
    int entrada;
    string sequencias;

    scanf("%d",&entrada);

    while (count_sequencias < entrada) {
        contador = 0;

        cin.ignore(); // Desconta um \n após o uso de um scanf
        getline(std::cin, sequencias);

        scanf("%d",&count_queries);
        string queries[count_queries];
        getline(std::cin, queries[contador]);

        // Armazena todas as queries em um array de string
        while(contador < count_queries) {
            getline(std::cin, queries[contador]);
            contador++; 
        }

        // Testa o caso de uso com todos os elementos do arrau de queries
        for (int j = 0; j < count_queries; j++) {
            if (buscaSubsequencia(sequencias, queries[j])) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }

        count_sequencias++;
    }
}   