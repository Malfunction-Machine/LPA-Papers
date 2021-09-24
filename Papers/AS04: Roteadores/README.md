# Roteadores

<br>

<!-- Shields do Projeto -->

<div align="center">

  <a href="https://www.urionlinejudge.com.br/judge/pt/problems/view/1774" alt="URI">
        <img src="https://img.shields.io/static/v1?label=URI&message=1774&color=black&style=for-the-badge&link=" /></a>
  
  <a href="#" alt="Assunto">
        <img src="https://img.shields.io/static/v1?label=ASSUNTO&message=GRAFOS&color=black&style=for-the-badge" /></a>

  <a href="#" alt="Level">
        <img src="https://img.shields.io/static/v1?label=LEVEL&message=3&color=CA1551&style=for-the-badge" /></a>


  <a href="https://www.udebug.com/URI/1774" alt="Debug">
        <img src="https://img.shields.io/badge/DEBUG-CC0000?style=for-the-badge" /></a>

</div>

<br>

## **Enunciado**

<br>

Bruno é o responsável por configurar os roteadores de uma empresa. Os roteadores transmitem os dados entre si através dos cabos de internet, Os dados transmitidos podem trafegar por uma ou mais rotas para serem entregues ao destinatário.

O preço dos cabos de rede utilizados nos roteadores da empresa pode chegar a ser muito caro, e a empresa precisa cortar gastos. Pensando nisso a empresa decidiu fazer algumas alterações na infra-estrutura de redes.

Bruno deve modificar a infra-estrutura da rede da empresa de forma com que todos os roteadores consigam transmitir dados entre si e exista somente uma rota entre cada par de roteadores, economizando o máximo possível de cabos de internet.

A sua tarefa é descobrir qual será o custo total com cabos que a empresa terá após as modificações feitas por Bruno. A figura abaixo mostra (a) a infraestrutura de redes atual; e (b) a infraestrutura de redes após as modificação feitas.

<br>

## **Entrada**

<br>

A primeira linha é composta por dois inteiros **R** (3 ≤ **R** ≤ 60) e **C** (**R** ≤ **C*** ≤ 200) representado respectivamente a quantidade de roteadores e a quantidade de cabos de internet utilizados atualmente.

Seguem C linhas, cada uma contendo três inteiros **V** (1 ≤ **V** ≤ **R**), **W** (1 ≤ **W** ≤ **R**) e **P** (1 ≤ **P** ≤ 10000), sendo **V** e **W** um par de roteadores que estão conectados por um cabo de internet e P o preço do cabo de internet utilizado.

**Exemplo de entrada:**

```text
7 12
1 3 6
1 4 9
2 3 17
2 5 32
2 7 27
3 4 11
3 5 4
4 5 3
4 6 19
5 6 13
5 7 15
6 7 5
```

<br>

## **Saída**

<br>

Seu programa deve imprimir um único valor inteiro que representa o custo total que a empresa gastará com cabos após as modificações.

**Exemplo de saida:**

```text
48
```

<br>

## **Observações**

<br>

 - A entrada e saida de exemplo estão disponíveis nos arquivos [**pub.in**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS04:%20Roteadores/pub.in) e [**pub.out**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS04:%20Roteadores/pub.out) respectivamente.
 - Para acessar a saida privada, basta acessar o debugger do URI pelo shields do projeto.