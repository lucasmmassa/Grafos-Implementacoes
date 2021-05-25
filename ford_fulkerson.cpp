// incluindo funcionalidades da biblioteca padrao
# include <iostream>
# include <fstream>
# include <vector>
# include <queue>
# include <utility>
# include <list>
# include <iterator>
# include <string.h>
# include <limits.h>

using namespace std;

#define infinito 9999999999999
typedef pair<int,int> intPair;

// definindo a estrutura do grafo
// sera usada matriz de adjacencia
// cada elemento da matriz sera um pair
// cada pair possuira a estrutura (vertice, destino, capacidade)

class Grafo{

    int nV; // numero de vertices
    list<intPair> *adjacentes; // matriz de adjacencia

    public:

    Grafo(int n);

    void adicionarAresta(int v1, int v2, int capacidade);

    void setAdjacente(list<intPair> *adjacentes);

    bool bfs(int **fluxo, int s, int t, int parent[]);

    int ford_fulkerson(int s, int t);

    void imprimirResultado();
};

// definindo o construtor
Grafo::Grafo(int n){ 

    this->nV = n;
    this->adjacentes = new list<intPair>[n];
}

// definindo adicao de aresta unidirecional
void Grafo::adicionarAresta(int v1, int v2, int capacidade){
    this->adjacentes[v1].push_back(make_pair(v2,capacidade));
}

void Grafo::setAdjacente(list<intPair> *adjacentes){
    this->adjacentes = adjacentes;
}

bool Grafo::bfs(int **fluxo, int s, int t, int parente[]){

    bool visitado[nV];

    for (int i = 0; i < nV; ++i) visitado[i] = false;

    queue<int> fila;
    fila.push(s);
    visitado[s] = true;
    parente[s] = -1;

    while(!fila.empty()){

        int u = fila.front();
        fila.pop();

        for (int v = 0; v < this->nV; v++){
            if(visitado[v] == false && fluxo[u][v] > 0){

                parente[v] = u;

                if(v==t){
                    return true;
                }

                fila.push(v);
                visitado[v] = true;
            }
        }
        
    }
    
    return false;
}

// funcao que imprime o resultado do algoritmo
void Grafo::imprimirResultado(){
    
}

// definindo a função ford_fulkerson
int Grafo::ford_fulkerson(int s, int t){

    int **fluxo = new int *[nV];
    int fluxo_max = 0;

    for(int i=0;i< nV; i++) fluxo[i] = new int[nV];

    for (int i = 0; i < nV; i++){
        for (int j = 0; j < nV; j++){
            fluxo[i][j] = 0;
        }
    }

    list<intPair>::iterator j;

    for(int i = 0; i < nV; i++){
        for(j = this->adjacentes[i].begin(); j != this->adjacentes[i].end(); j++){
            fluxo[i][(*j).first] = (*j).second;
        }
    }

    int parente[nV];

    while(bfs(fluxo, s, t, parente)){

        int fluxo_caminho = INT_MAX;

        for (int v = t; v != s; v = parente[v]) {
            int u = parente[v];
            fluxo_caminho = min(fluxo_caminho, fluxo[u][v]);
        }

        for (int v = t; v != s; v = parente[v]) {
            int u = parente[v];
            fluxo[u][v] -= fluxo_caminho;
            fluxo[v][u] += fluxo_caminho;
        }
 
        fluxo_max += fluxo_caminho;
    }

    return fluxo_max;
}

int main(){

    int n_de_vertices, n_arestas, u,v,c;

    ifstream arquivo;
    arquivo.open("data.txt");

    arquivo >> n_de_vertices >> n_arestas;

    Grafo g(n_de_vertices);
    
    while (n_arestas--){
        arquivo >> u >> v >> c;
        g.adicionarAresta(u-1, v-1, c);
    }
    
    cout << "Fluxo maximo: " << g.ford_fulkerson(0,n_de_vertices-1) << endl;

    return 0;
};
