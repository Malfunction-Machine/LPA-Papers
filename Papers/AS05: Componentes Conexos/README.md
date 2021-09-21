# Componentes Conexos

<br>

<!-- Shields do Projeto -->

<div align="center">

  <a href="https://www.urionlinejudge.com.br/judge/pt/problems/view/1082" alt="URI">
        <img src="https://img.shields.io/static/v1?label=URI&message=1082&color=black&style=for-the-badge&link=" /></a>
  
  <a href="#" alt="Assunto">
        <img src="https://img.shields.io/static/v1?label=ASSUNTO&message=Grafos&color=black&style=for-the-badge" /></a>

  <a href="#" alt="Level">
        <img src="https://img.shields.io/static/v1?label=LEVEL&message=5&color=ED2B88&style=for-the-badge" /></a>


  <a href="https://www.udebug.com/URI/1082" alt="Debug">
        <img src="https://img.shields.io/badge/DEBUG-00599C?style=for-the-badge" /></a>

</div>

<br>

<div style="text-align: justify"> 

<br>

## **Enunciado**

<br>

***Grafo conexo***: Um grafo G(V,A) é conexo se para cada par de nodos u e v existe um caminho entre u e v. Um grafo com apenas um componente é um grafo conexo.

***Grafo desconexo***: Um grafo G(V,A) é desconexo se ele for formado por 2 ou mais componentes conexos.

***Componente conexo***: Componentes conexos de um grafo são os subgrafos conexos deste grafo.

Com base nestes conceitos, onde cada entrada fornecida que tem a identificação de cada um dos vértices, arestas e as ligações entre os vértices através destas arestas,  liste cada um dos componentes conexos que existem no grafo, segundo a entrada fornecida.

<br>

## **Entrada**

<br>

A primeira linha do arquivo de entrada contém um valor inteiro N que representa a quantidade de casos de teste que vem a seguir. Cada caso de teste contém dois valores V e E que são, respectivamente, a quantidade de Vértices e arestas (Edges) do grafo. Seguem E linhas na sequência, cada uma delas representando uma das arestas que ligam tais vértices. Cada vértice é representado por uma letra minúscula do alfabeto ('a'-'z'), ou seja, cada grafo pode ter no máximo 26 vértices. Cada grafo tem no mínimo 1 componente conexo.

<br>

## **Saída**

<br>

Para cada caso de teste da entrada, deve ser apresentada uma mensagem Case #n:, onde n indica o número do caso de teste (conforme exemplo abaixo). Segue a listagem dos vértices de cada segmento, um segmento por linha, separados por vírgula (inclusive com uma virgula no final da linha). Finalizando o caso de teste, deve ser apresentada uma mensagem indicando a quantidade de componentes conexos do grafo (em inglês). Todo caso de teste deve ter uma linha em branco no final, inclusive o último caso de teste.

<div align="center">

| Exemplo entrada |        Exemplo saida         |    
|:--------------- |:-----------------------------|
|      3          |     Case #1:                 |
|     3 1         |     a,c,                     |
|     a c         |     b,                       |
|    10 10        |     2 connected components   |
|     a b         |                              |
|     a c         |     Case #2:                 |
|     a g         |     a,b,c,g,                 |
|     b c         |     d,e,f,                   |
|     c g         |     h,i,j,                   |
|     e d         |     3 connected components   |
|     d f         |                              |
|     h i         |     Case #3:                 |
|     i j         |     a,b,c,                   |
|     j h         |     d,                       |
|     6 4         |     e,f,                     |
|     a b         |     3 connected components   |
|     b c         |                              |
|     c a         |                              |
|     e f         |                              |    

</div>

<br>

## **Observações**

<br>

 - Os vértices de cada caso de teste sempre iniciam no 'a'. Isso significa que um caso de teste que tem 3 vértices, tem obrigatoriamente os vértices 'a', 'b' e 'c'. 
 - Os nodos devem sempre ser apresentados em ordem crescente e se há caminho de a até b significa que há caminho de b até a.
 - Para acessar a saida privada, basta acessar o debugger do URI

</div>