/* 
 * Tarefa: Bolhas e Baldes (Estruturas e Bibliotecas)
 * Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
 * Nome: Thiago Henriques Nogueira
 * Matricula: 655085
 * Professor: Wladmir Cardoso Brandão
 * Complexiadade: O( O(n*log n)) onde n é o tamanho da sequencia a ser tratada para a realização das jogadas possíveis
 *                
*/

#include <iostream>

class BolhasBaldes {

    private:

        void merge(int sequencia[], int esq, int  mid, int  dir)
        {    
            auto subArrayUm = mid - esq + 1;
            auto subArrayDois = dir - mid;

            // Arrays temporarios 
            auto *esqArray = new int[subArrayUm],
                 *dirArray = new int[subArrayDois];
        
            // Passando dados para arrays temporarios esqArray[] and dirArray[]
            for (auto i = 0; i < subArrayUm; i++)
                esqArray[i] = sequencia[esq + i];
            for (auto j = 0; j < subArrayDois; j++)
                dirArray[j] = sequencia[mid + 1 + j];
        
            auto indexSubArrayUm   = 0,  // Index da primeira sub-sequencia
                 indexSubArrayDois = 0;  // Index da segunda sub-sequencia
            int indexOfMergedArray = esq; // Index da sequencia merge
        
            // Merge os arrays temporarios para sequencia[esq..dir]
            while (indexSubArrayUm < subArrayUm && indexSubArrayDois < subArrayDois) {
                if (esqArray[indexSubArrayUm] < dirArray[indexSubArrayDois]) {
                    sequencia[indexOfMergedArray] = esqArray[indexSubArrayUm++];
                }
                else {
                    sequencia[indexOfMergedArray] = dirArray[indexSubArrayDois++];
                    num_jogadas += subArrayUm - indexSubArrayUm;
                }
                indexOfMergedArray++;
            }

            // Copia os elementos do array denominado esq[]
            while (indexSubArrayUm < subArrayUm) {
                sequencia[indexOfMergedArray++] = esqArray[indexSubArrayUm++];
            }
           
            // Copia os elementos do array denominado dir[]
            while (indexSubArrayDois < subArrayDois) {
                sequencia[indexOfMergedArray++] = dirArray[indexSubArrayDois++];
            }
        }
        
        void mergeSort(int sequencia[], int  comeco, int  fim) {
            
            if (comeco >= fim)
                return; // Retorno recursivo

            auto mid = comeco + (fim - comeco) / 2;
            mergeSort(sequencia, comeco, mid);
            mergeSort(sequencia, mid + 1, fim);
            return merge(sequencia, comeco, mid, fim);
        }

    public:

        int num_jogadas;

        // Inicia partida do jogo
        void partida(int sequencia[], int comeco, int fim) {
            num_jogadas = 0;
            this->mergeSort(sequencia, comeco, fim);
        }

        // Imprimi o nome do vencendor
        void vencendor() {
            if(num_jogadas % 2) {
                std::cout << "Marcelo" << std::endl;    

            } else {
                std::cout << "Carlos" << std::endl;    

            }

        }
};

int main(int argc, char  *argv[]) {
    int N;
    BolhasBaldes jogo;
    std::cin >> N;

    while(N != 0) {

        int sequencia[N];

        for(int i = 0; i < N; i++) {
            std::cin >> sequencia[i]; 
        }

        jogo.partida(sequencia, 0, N - 1);

        jogo.vencendor();

        std::cin >> N;
    }
}