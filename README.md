# Teoria dos Grafos - Trabalho de Implementação de Algoritmos

## Dupla
- Jhonnye Gabriel de Oliveira Farias - e-mail: jgof@ic.ufal.br - GitHub: https://github.com/jhonnye0
- Lucas Mendes Massa - e-mail: lmm@ic.ufal.br - GitHub: https://github.com/lucasmmassa

## Descrição

O trabalho tem como objetivo colocar em prática conceitos aprendidos na disciplina de Teoria dos Grafos, através da implementação de quatro algoritmos para grafos. Os algoritmos escolhidos foram:

- Prim: árvore geradora mínima.
- Kruskal: árvore geradora mínima.
- Dijkstra: distância mínima entra origem e demais vértices.
- Ford-Fulkerson: fluxo máximo em um grafo direcionado.

No que concerne ao formato de entrada, todos os algoritmos implementados reconhecem o mesmo padrão para a entrada, a qual será lida de um arquivo de texto. Considerando n o número de vértices, m o número de arestas, (u,v) uma aresta qualquer e p o peso da aresta, os algoritmos funcionam baseados no seguinte formato de entrada:

````
n m
u v p
u v p
u v p
.
.
.

até serem inseridas as m arestas
````
Vale salientar que todos os algoritmos implementados consideram que o grafo dado na entrada é não direcionado, exceto o de Ford-Fulkerson.

Abaixo seguem mais alguns detalhes a respeito da entrada e saída, além de como compilar e executar os códigos.

## Algoritmo de Prim

Para o algoritmo de Prim temos a seguinte descrição:

````
Entrada: grafo não direcionado em arquivo de texto, no formato apresentado.
````
````
Saída: lista das arestas pertencentes à árvore geradora mínima no formato:
(u,v)
(u,v)
.
.
.

seguida do peso total da árvore.
````

## Algotimo de Kruskal

Para o algoritmo de Kruskal temos a seguinte descrição:

````
Entrada: grafo não direcionado em arquivo de texto, no formato apresentado.
````
````
Saída: lista das arestas pertencentes à árvore geradora mínima no formato:
(u,v)
(u,v)
.
.
.

seguida do peso total da árvore.
````

## Algoritmo de Dijkstra

Para o algoritmo de Dijkstra temos a seguinte descrição:
````
Entrada: grafo não direcionado em arquivo de texto, no formato apresentado.
````
Vale salientar que o primeiro vértice v1 sempre será considerado como origem na presente implementação.
````
Saída: lista contendo a distância mínima do vértice origem até o vértice destino, no formato:
destino ---- distância
destino ---- distância
destino ---- distância
.
.
.
```` 

## Algoritmo de Ford-Fulkerson

Para o algoritmo de Ford-Fulkerson temos a seguinte descrição:

````
Entrada: grafo não direcionado em arquivo de texto, no formato apresentado. Os pesos serão considerados como as capacidades das arestas.
````
Vale salientar que o primeiro vértice v1 sempre será considerado como fonte e o último vértice vm como sumidouro na presente implementação. Além disso, é importante ressaltar que foi usada a abordagem de Edmonds–Karp, através de uma busca em largura para encontrar os caminhos presentes no residual.
````
Saída: fluxo máximo entre fonte e sumidouro do grafo direcionado dado na entrada.
```` 