# Cavalo

<br>

<!-- Shields do Projeto -->

<div align="center">

  <a href="https://www.beecrowd.com.br/judge/pt/problems/view/1513" alt="URI">
        <img src="https://img.shields.io/static/v1?label=URI&message=1513&color=black&style=for-the-badge&link=" /></a>
  
  <a href="#" alt="Assunto">
        <img src="https://img.shields.io/static/v1?label=ASSUNTO&message=Paradigmas&color=black&style=for-the-badge" /></a>

  <a href="#" alt="Level">
        <img src="https://img.shields.io/static/v1?label=LEVEL&message=9&color=4328f6&style=for-the-badge" /></a>


  <a href="https://www.udebug.com/URI/1513" alt="Debug">
        <img src="https://img.shields.io/badge/DEBUG-CC0000?style=for-the-badge" /></a>

</div>

<br>

<div style="text-align: justify"> 

<br>

## **Enunciado**

<br>

Rafael gosta tanto de jogar xadrez que resolveu inventar novas maneiras de se desafiar. Dessa vez ele resolveu jogar com a peça do cavalo, pois a forma como ela se movimenta pareceu adicionar um pouco de dificuldade ao jogo, segundo Rafael.

O desafio é o seguinte: Há um cavalo e **K** peões no tabuleiro. Dada uma posição inicial do cavalo e dos peões, qual a menor quantidade de movimentos necessários para capturar os **K** peões e voltar à posição inicial?

Lembre que a peça do cavalo pode mover-se usando saltos de formato L, ou seja, duas posições para a vertical e uma posição para a horizontal, ou duas posições para a horizontal e uma posição para a vertical. Para capturar um peão, basta ocupar a mesma posição que ele no tabuleiro.

<br>

## **Entrada**

<br>

Haverá diversos casos de teste. Cada caso de teste inicia com três inteiro **N**, **M** e **K** (5 ≤ **N**, **M** ≤ 100, 2 ≤ **K** ≤ 15), representando, respectivamente, a quantidade de linhas e de colunas do tabuleiro, e a quantidade de peões a serem capturados.

As próximas **N** linhas irão conter **M** caracteres cada, onde o caractere na linha **i** e coluna **j** indica que na posição **[i, j]** do tabuleiro há:

- '.' uma posição válida onde o cavalo pode pular.
- '#' uma posição inválida onde o cavalo não pode pular.
- 'C' a posição inicial do cavalo de Rafael.
- 'P' a posição de um dos K peões o qual Rafael deve capturar.

O último caso de teste é indicado quando **N** = **M** = **K** = 0, o qual não deve ser processado.

**Exemplo de entrada:**

```text
5 5 2
.....
.P...
...P.
.....
..C..
4 6 2
.P##.P
..##..
..##..
..C...
0 0 0
```

<br>

## **Saída**

<br>

Para cada caso de teste, imprima um inteiro, representando a quantidade mínima de saltos que o cavalo de Rafael deve fazer para capturar os **K** peões e retornar à posição inicial.

É garantido que sempre haverá ao menos uma maneira de capturar todos os peões.

**Exemplo de saida:**

```text
4
8
```

<br>

## **Observações**

<br>

- A entrada e saida de exemplo estão disponíveis nos arquivos [**pub.in**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS11:%20Cavalo/pub.in) e [**pub.out**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS11:%20Cavalo/pub.out) respectivamente.
- Para acessar a saida privada, basta acessar o debugger do URI pelo shields do projeto.

</div>