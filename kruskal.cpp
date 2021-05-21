#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
  
typedef pair <int, int> IntegerPair;

struct Graph{
    int V, E;
    bool directed = false;

    vector< pair<int, IntegerPair> > edges;
  
    Graph(int V, int E, int directed){
        this->V = V;
        this->E = E;
        this->directed = directed;
    }
  
    void addEdge(int u, int v, int w){
        edges.push_back({w, {u, v}});

        if(directed)
            edges.push_back({w, {v, u}});
    }
  
    int kruskalMST();
};

struct UnionFind{

    int *parent, *size;
    int n;
  
    UnionFind(int n){
        
        this->n = n;
        this->parent = new int[n+1];
        this->size = new int[n+1];
  
        for (int i = 0; i <= n; i++){

            this->size[i] = 0;
            this->parent[i] = i;
        }
    }
  
    int find(int u){
        
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  
    void _union(int x, int y){

        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot == yRoot) return;
  
        if (size[xRoot] < size[yRoot]){

            int aux = xRoot;
            xRoot= yRoot;
            yRoot= aux;
        } 

        parent[yRoot] = xRoot;
        size[xRoot] += size[yRoot];
    }
};
  
int Graph::kruskalMST()
{
    int weight = 0;
  
    sort(edges.begin(), edges.end());
 
    UnionFind uf(V);
 
    vector< pair<int, IntegerPair> >::iterator it;

    for (it=edges.begin(); it!=edges.end(); it++){

        int u = it->second.first;
        int v = it->second.second;
  
        int set_u = uf.find(u);
        int set_v = uf.find(v);
  
        if (set_u != set_v){

            cout << u << " - " << v << endl;
  
            weight += it->first;
  
            uf._union(set_u, set_v);
        }
    }
  
    return weight;
}
  
int main(){

    int V = 9, E = 14;

    Graph g(V, E, true);
  
    g.addEdge(0, 1, 14);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 12);
    g.addEdge(2, 5, 24);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 9);
  
    cout << "Edges of MST are: \n";
    int mst_wt = g.kruskalMST();
  
    cout << "\nWeight of MST is: " << mst_wt;
  
    return 0;
}
