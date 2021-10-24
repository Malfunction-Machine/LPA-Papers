/*
* Tarefa: Notas e Moedas (Algoritmos Gulosos)
* Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
* Nome: Thiago Henriques Nogueira
* Matricula: 655085
* Professor: Wladmir Cardoso Brandão
* Complexiadade: O(n) onde n é a quantidade de valores disponiveis para notas e moedas.
                 O intuito do problema é passar com o valor total de todos os valores (começando da maior 
                 nota R$100.00 e terminando da menor moeda R$0.01)
*/

#include <iostream>
#include <iomanip>      

class NotasMoedas {

    private:

    /* 
    *  array de double que armazena todos os valores monetarios disponiveis
    *  posição 0 á 5: valores das notas
    *  posição 6 à 11: valores das moedas
    */
    double NotasMoedas[12] = {100.0,50.0,20.0,10.0,5.0,2.0,1.0,0.5,0.25,0.10,0.05,0.01};

    public:
    
    /*
     * Decompõe o valor
     * @entrada ponteiro de ponteiro de double relativo ao valor a ser decomposto
     * @entrada double relativo a nota ou moeda selecionada para a decomposição
     * @saida int relativo a quantidade de notas ou moedas retornadas pela decomposição        
    */ 
    int decompositor(double** valor_monetario, double nota_moeda) {
        int quantidade;

        quantidade = **valor_monetario / nota_moeda;

        **valor_monetario -= (int)quantidade * nota_moeda;

        return quantidade;
    }


    /*
     * Imprimir a saída para o problema
     * @entrada ponteiro de double relativo ao valor passado
    */ 
    void imprimir(double* valor_monetario) {
        std::cout.precision(2);
        std::cout << std::fixed;

        std::cout << "NOTAS:" << std::endl;
        
        for(int i = 0; i < 6; i++) {
            std::cout << decompositor(&valor_monetario,NotasMoedas[i]) << " nota(s) de R$ " << NotasMoedas[i] << std::endl;
        }
        
        std::cout << "MOEDAS:" << std::endl;

        for(int i = 6; i < 12; i++) {
            std::cout << decompositor(&valor_monetario,NotasMoedas[i]) << " moeda(s) de R$ " << NotasMoedas[i] << std::endl;

        }

    }

};

int main() {
    double valor_monetario;
    NotasMoedas valor;

    std::cin >> valor_monetario;

    valor.imprimir(&valor_monetario); 
}