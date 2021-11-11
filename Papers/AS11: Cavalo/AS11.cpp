/*
* Tarefa: Cavalo (Back Tracking)
* Disciplina: LABORATÓRIO DE PROJETO DE ALGORITMOS
* Nome: Thiago Henriques Nogueira
* Matricula: 655085
* Professor: Wladmir Cardoso Brandão
* Complexiadade: O(N * M) onde N corresponde a quantidade de linhas e M a quantidade de 
                 colunas do Tabuleiro em questão. Na solução será necessário percorrer
			     por todo o Tabuleiro para se achar as posições onde o Cavalo pode ir, 
				 as posições onde se encontram os Peões e as posições invalidas para o 
				 deslocamento do Cavalo. Por conta de todos esses fatores, é necessario 
				 realizar uma leitura completa.

*/

#include <iostream>
#include <queue>
#include <bits/stdc++.h>

char TABULEIRO[110][110];
int VALORES[110][110];
int AUXILIAR[110][110];
int DISTANCIA[20][20];
int DIST_PEAO[1 << 17][17];
int DIST_X[] = {1, 1, 2, 2, -1, -1, -2, -2};
int DIST_Y[] = {2, -2, 1, -1, 2, -2, 1, -1};

/*
 * Função que verfica se a as coordenadas selecionadas do Tabuleiro são válidas
 * @entrada int count_linhas referente a coluna acessada do Tabuleiro
 * @entrada int count_colunas referente a coluna acessada do Tabuleiro
 * @entrada int N referente a quantidade total de linhas do Tabuleiro
 * @entrada int M referente a quantidade total de colunas do Tabuleiro
 * @saida bool para identificar se a posição selecionada é váida ou não
*/
bool preencheTabuleiro(int count_linhas, int count_colunas, int N, int M) {
	return !(count_linhas < 0 || count_linhas >= N || count_colunas < 0 || count_colunas >= M || TABULEIRO[count_linhas][count_colunas] == '#');
}

/*
 * Função responsavel por fornecer a resposta
 * @entrada int iniciar
 * @entrada int finalizar
 * @entrada int K referente a quantidade total de pĩoes no Tabuleiro
 * @saida int resposta referente a menor movimentação que o Cavalo pode realizar e posteriormente voltar 
 *        para sua posição inicial
*/
int calulaMovimentacao(int iniciar, int finalizar, int K) {
	if(iniciar == (1<<K)-1) {
    	return DISTANCIA[finalizar][0];
    }
	
    int &resposta = DIST_PEAO[iniciar][finalizar];
	
    if(resposta != -1) {
		return resposta;
    }

    resposta = INT_MAX;
	
    for(int count_linhas = 0; count_linhas < K; count_linhas++) {
		if(!(iniciar&(1<<count_linhas))) {
        	resposta = std::min(resposta, DISTANCIA[finalizar][count_linhas] + calulaMovimentacao(iniciar|(1<<count_linhas), count_linhas, K));
        }

    }

    return resposta;
}

/*
 * Realiza uma busca em largura dado uma linha e uma coluna do Tabuleiro
 * @entrada int count_linhas referente a linha acessada do Tabuleiro
 * @entrada int count_colunas referente a coluna acessada do Tabuleiro
 * @entrada int N referemte a quantidade total de linhas do Tabuleiro
 * @entrada int M referente a quantidade total de colunas do Tabuleiro
*/
void bfs(int count_linhas, int count_colunas, int N, int M) {

	for(int count_linhas = 0; count_linhas < N; count_linhas++) {
		for(int count_colunas = 0; count_colunas < M; count_colunas++) {
        	AUXILIAR[count_linhas][count_colunas] = INT_MAX;
        }
    }

    AUXILIAR[count_linhas][count_colunas] = 0;
	std::queue<std::pair<int, int>> lista;
	lista.push({count_linhas, count_colunas});

	while(!lista.empty()) {
		int x = lista.front().first, y = lista.front().second; lista.pop();
		
		if(VALORES[x][y] != -1)
			DISTANCIA[VALORES[count_linhas][count_colunas]][VALORES[x][y]] = AUXILIAR[x][y];

		for(int count_linhas = 0; count_linhas < 8; count_linhas++) {
			int nx = x + DIST_X[count_linhas], ny = y + DIST_Y[count_linhas];
			
            if(preencheTabuleiro(nx, ny, N, M) && AUXILIAR[nx][ny] == INT_MAX) {
				lista.push({nx, ny});
				AUXILIAR[nx][ny] = 1+AUXILIAR[x][y];
			}
		}
	}
}

int main() {
    int N, M, K;
    int count_linhas;

    std::cin >> N >> M >> K;

	while(N + M + K != 0) {
		int id = 1;
		memset(VALORES, -1, sizeof(VALORES));
		
        count_linhas = 0;
        while(count_linhas < N) {
            std::cin >> TABULEIRO[count_linhas];

            for(int count_colunas = 0; count_colunas < M; count_colunas++) {
				DISTANCIA[count_linhas][count_colunas] = INT_MAX;

				if(TABULEIRO[count_linhas][count_colunas] == 'C')
					VALORES[count_linhas][count_colunas] = 0;
                
                else if(TABULEIRO[count_linhas][count_colunas] == 'P')
                    VALORES[count_linhas][count_colunas] = id++;
            }

            count_linhas++;
        }
        
		K++;
        count_linhas = 0;

        while(count_linhas < N) {
            for(int count_colunas = 0; count_colunas < M; count_colunas++)
				if(VALORES[count_linhas][count_colunas] != -1)
                	bfs(count_linhas, count_colunas, N, M);

            count_linhas++;
        }

		memset(DIST_PEAO, -1, sizeof(DIST_PEAO));
		std::cout << calulaMovimentacao(1, 0, K) << std::endl;

        std::cin >> N >> M >> K;
	}
}