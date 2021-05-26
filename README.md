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
Vale salientar que todos os valores contidos na entrada (n,m,u,v,p) devem ser números inteiros e que os vértices são contados a partir do 1, não do 0. Além disso, todos os algoritmos implementados consideram que o grafo dado na entrada é não direcionado, exceto o de Ford-Fulkerson.

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

Para compilar o código, caso esteja em um sistema Linux, basta estar no diretório clonado deste repositório e fazer uso do makefile:
````
make prim
````
ou, caso prefira, digitar no terminal:
````
g++ prim.cpp -o prim
````
Para executar o código compilado, basta estar no mesmo diretório e digitar no terminal:
````
./prim <nome do arquivo contendo o grafo>
````

Caso esteja no Windows, basta compilar no cmd através do comando:
````
g++ prim.cpp -o prim.exe
````
e executar pelo comando:
````
.\prim.exe <nome do arquivo contendo o grafo>
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
Para compilar o código, caso esteja em um sistema Linux, basta estar no diretório clonado deste repositório e fazer uso do makefile:
````
make kruskal
````
ou, caso prefira, digitar no terminal:
````
g++ kruskal.cpp -o kruskal
````
Para executar o código compilado, basta estar no mesmo diretório e digitar no terminal:
````
./kruskal <nome do arquivo contendo o grafo>
````

Caso esteja no Windows, basta compilar no cmd através do comando:
````
g++ kruskal.cpp -o kruskal.exe
````
e executar pelo comando:
````
.\kruskal.exe <nome do arquivo contendo o grafo>
````
## Algoritmo de Dijkstra

Para o algoritmo de Dijkstra temos a seguinte descrição:
````
Entrada: grafo, direcionado ou não, em arquivo de texto no formato apresentado.
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
Para compilar o código, caso esteja em um sistema Linux, basta estar no diretório clonado deste repositório e fazer uso do makefile:
````
make dijkstra
````
ou, caso prefira, digitar no terminal:
````
g++ dijkstra.cpp -o dijkstra
````
Para executar o código compilado, basta estar no mesmo diretório e digitar no terminal:
````
./dijkstra <nome do arquivo contendo o grafo>
````

Caso esteja no Windows, basta compilar no cmd através do comando:
````
g++ dijkstra.cpp -o dijkstra.exe
````
e executar pelo comando:
````
.\dijkstra.exe <nome do arquivo contendo o grafo>
````
## Algoritmo de Ford-Fulkerson

Para o algoritmo de Ford-Fulkerson temos a seguinte descrição:

````
Entrada: grafo direcionado em arquivo de texto, no formato apresentado. Os pesos serão considerados como as capacidades das arestas.
````
Vale salientar que o primeiro vértice v1 sempre será considerado como fonte e o último vértice vm como sumidouro na presente implementação. Além disso, é importante ressaltar que foi usada a abordagem de Edmonds–Karp, através de uma busca em largura para encontrar os caminhos presentes no residual.
````
Saída: fluxo máximo entre fonte e sumidouro do grafo direcionado dado na entrada.
```` 
Para compilar o código, caso esteja em um sistema Linux, basta estar no diretório clonado deste repositório e fazer uso do makefile:
````
make ff
````
ou, caso prefira, digitar no terminal:
````
g++ ford_fulkerson.cpp -o ford_fulkerson
````
Para executar o código compilado, basta estar no mesmo diretório e digitar no terminal:
````
./ford_fulkerson <nome do arquivo contendo o grafo>
````

Caso esteja no Windows, basta compilar no cmd através do comando:
````
g++ ford_fulkerson.cpp -o ford_fulkerson.exe
````
e executar pelo comando:
````
.\ford_fulkerson.exe <nome do arquivo contendo o grafo>
````
