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