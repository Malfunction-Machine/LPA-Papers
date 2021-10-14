# Bolhas e Baldes
<br>

<!-- Shields do Projeto -->

<div align="center">

  <a href="https://www.urionlinejudge.com.br/judge/pt/problems/view/1088" alt="URI">
        <img src="https://img.shields.io/static/v1?label=URI&message=1088&color=black&style=for-the-badge" /></a>
  
  <a href="#" alt="Assunto">
        <img src="https://img.shields.io/static/v1?label=ASSUNTO&message=Estruturas e Bibliotecas&color=black&style=for-the-badge" /></a>

  <a href="#" alt="Level">
        <img src="https://img.shields.io/static/v1?label=LEVEL&message=6&color=brown&style=for-the-badge" /></a>


  <a href="https://www.udebug.com/URI/1088" alt="Debug">
        <img src="https://img.shields.io/badge/DEBUG-CC0000?style=for-the-badge" /></a>

</div>

<br>

<div style="text-align: justify"> 

<br>

## **Enunciado**

<br>

Andrea, Carlos e Marcelo são muito amigos e passam todos os finais de semana à beira da piscina. Enquanto Andrea se bronzeia ao sol, os dois ficam jogando Bolhas. Andrea, uma cientista da computação muito esperta, já disse a eles que não entende por que passam tanto tempo jogando um jogo tão primário.

Usando o computador portátil dela, os dois geram um inteiro aleatório N e uma seqüência de inteiros, também aleatória, que é uma permutação de *1, 2, ... ,N*.

O jogo então começa, cada jogador faz um movimento, e a jogada passa para o outro jogador. Marcelo é sempre o primeiro a começar a jogar. Um movimento de um jogador consiste na escolha de um par de elementos consecutivos da seqüência que estejam fora de ordem e em inverter a ordem dos dois elementos. Por exemplo, dada a seqüência 1, 5, 3, 4, 2, o jogador pode inverter as posições de 5 e 3 ou de 4 e 2, mas não pode inverter as posições de 3 e 4, nem de 5 e 2. Continuando com o exemplo, se o jogador decide inverter as posições de 5 e 3 então a nova seqüência será 1, 3, 5, 4, 2.

Mais cedo ou mais tarde, a seqüência ficará ordenada. Perde o jogador impossibilitado de fazer um movimento. Andrea, com algum desdém, sempre diz que seria mais simples jogar cara ou coroa, com o mesmo efeito. Sua missão, caso decida aceitá-la, é determinar quem ganha o jogo, dada a seqüência inicial.

<br>

## **Entrada**

<br>

A entrada contém vários casos de teste. Os dados de cada caso de teste estão numa única linha, e são inteiros separados por um espaço em branco. Cada linha contém um inteiro **N** (2 ≤ **N** ≤ 105), seguido da seqüência inicial P = (X1, X2, ...,XN) de N inteiros distintos dois a dois, onde 1 ≤ Xi ≤ **N** para 1 ≤ i ≤ **N**.

O final da entrada é indicado por uma linha que contém apenas o número zero.

<br>

## **Saída**

<br>

Para cada caso de teste da entrada seu programa deve imprimir uma única linha, com o nome do vencedor, igual a Carlos ou Marcelo., sem espaços em branco.

<br>

## **Observações**

<br>

  - A entrada e saida de exemplo estão disponíveis nos arquivos [**pub.in**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS08:%20Bolhas%20e%20Baldes/pub.in) e [**pub.out**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS08:%20Bolhas%20e%20Baldes/pub.out) respectivamente.
 - Para acessar a saida privada, basta acessar o debugger do URI pelo shields do projeto.

</div>