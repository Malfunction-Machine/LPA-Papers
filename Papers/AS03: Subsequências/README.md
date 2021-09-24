# LED

<br>

<!-- Shields do Projeto -->

<div align="center">

  <a href="https://www.urionlinejudge.com.br/judge/pt/problems/view/1507" alt="URI">
        <img src="https://img.shields.io/static/v1?label=URI&message=1507&color=black&style=for-the-badge&link=" /></a>
  
  <a href="#" alt="Assunto">
        <img src="https://img.shields.io/static/v1?label=ASSUNTO&message=ESTRUTURAS E BIBLIOTECAS&color=black&style=for-the-badge" /></a>

  <a href="#" alt="Level">
        <img src="https://img.shields.io/static/v1?label=LEVEL&message=7&color=D72638&style=for-the-badge" /></a>


  <a href="https://www.udebug.com/URI/1161" alt="Debug">
        <img src="https://img.shields.io/badge/DEBUG-CC0000?style=for-the-badge" /></a>

</div>

 

<br>

## **Enunciado**

<br>

Dado duas sequências, diga se a segunda é uma subsequência da primeira.

<br>

## **Entrada**

<br>

A entrada comeca com um inteiro **N** (0 < **N** <= 10), o número de casos de teste. Seguem N casos testes. Um caso de teste comeca com uma sequência de caracteres **S** (**S** in [a-zA-Z], 0 < |**S**| < 100000). Segue um inteiro **Q** (0 < **Q** <= 1000), o número de queries. As proximas **Q** linhas sao compostas por uma sequência de carateres **R** (**R** in [a-zA-Z], 0 < |**R**| < 100) cada.

**Exemplo de entrada:**

```text
1
aabccbba
2
abc
abbc
```

<br>

## **Saída**

<br>

Para cada querie **R**, imprima "Yes" (sem aspas) se **R** for uma subsequência de **S**, ou "No" (sem aspas), caso contrario.

**Exemplo de saida:**

```text
Yes
No
```

<br>

## **Observações**

<br>

 - A entrada e saida de exemplo estão disponíveis nos arquivos [**pub.in**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS03:%20Subsequ%C3%AAncias/pub.in) e [**pub.out**](https://github.com/Malfunction-Machine/LPA-Papers/blob/main/Papers/AS03:%20Subsequ%C3%AAncias/pub.out) respectivamente.
 - Para acessar a saida privada, basta acessar o debugger do URI pelo shields do projeto.