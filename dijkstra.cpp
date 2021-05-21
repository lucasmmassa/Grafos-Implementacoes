#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

#define MAX 101
const int inf = 1e9;

using namespace std;

struct Graph{

    int V, E;
    bool directed = false;
    int cost[MAX];
    
    vector<pair<int, int> > edges[MAX];

    Graph(int V, int E, int directed){
        this->V = V;
        this->E = E;
        this->directed = directed;
    }
  
    void addEdge(int u, int v, int w){
        edges[u].push_back({v, w});

        if(directed)
            edges[v].push_back({u, w});
    }

    int dijkstra(int source, int target);
};

int Graph::dijkstra(int source, int target){
    // Setando as distâncias para infinito
	for (int i = 1; i < MAX; ++i) cost[i] = inf;

	priority_queue <pair<int, int> > pq;
    
    // Setando o custo do nó inicial para ele mesmo com 0
	cost[source] = 0; 
    // Adicionando o nó inicial na fila de prioridade
    pq.push({source, cost[source]});
	

	while(!pq.empty()){
        // Pega o primeiro valor da fila
		int u = pq.top().first; 

        // Remove-o da fila
        pq.pop();

        // Percorre todos os nós adjacentes a u

        vector<pair<int, int> >::iterator it;

		for (it=edges[u].begin(); it!=edges[u].end(); it++){

            int w = it->second;
            int v = it->first;

            // Se o custo atual de source ate o nó u somado com
            // o custo do peso w entre u,v
            // For menor que o custo de source até v, então atualize o custo de source ate v para
            // Custo de u + peso de u até v e adicione v na fila de prioridade.
            
            if(cost[u] + w < cost[v]){
                cost[v] = cost[u] + w;
                pq.push({v, cost[v]});
            }
		}
        
	}

	return cost[target];
}

int main()
{
    int V = 9, E = 14;
    Graph g(V, E, true);
  
    // Criando o grafo
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

	// Chamando dijkstra para o grafo G com nó inicial 1 e final 7.
	cout << g.dijkstra(1, 7);

	return 0;
}
