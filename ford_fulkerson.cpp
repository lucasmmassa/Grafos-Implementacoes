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

#define infinito 999999999
typedef pair<int,int> intPair;

// definindo a estrutura do grafo
// sera usada matriz de adjacencia
// cada elemento da matriz sera um pair
// cada pair possuira a estrutura (vertice, destino, capacidade)

class Grafo{

    int nV; // numero de vertices
    list<intPair> *adjacentes; // matriz de adjacencia
    int resultado;

    public:

    Grafo(int n);

    void adicionarAresta(int v1, int v2, int capacidade);

    void setAdjacente(list<intPair> *adjacentes);

    bool bfs(int **residual, int s, int t, int parent[]);

    void ford_fulkerson(int s, int t);

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

// Função que realiza uma busca em largura considerando a capacidade de fluxo atual do grafo residual
bool Grafo::bfs(int **residual, int s, int t, int parente[]){

    bool visitado[this->nV];

    for (int i = 0; i < nV; ++i) visitado[i] = false;

    queue<int> fila;
    // Sempre iniciando com o nó fonte
    fila.push(s);
    visitado[s] = true;
    parente[s] = -1;

    while(!fila.empty()){

        int u = fila.front();
        fila.pop();

        for (int v = 0; v < this->nV; v++){
            //Nesse ponto é checado se o nó já foi visitado e
            // se ainda é possível aumentar o fluxo na aresta e=(u,v)
            if(visitado[v] == false && residual[u][v] > 0){
                
                parente[v] = u;
                // Se foi possível atingir o nó sumidouro retornar verdadeiro
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
    cout << "Fluxo maximo: " << this->resultado << endl;
}

// definindo a função ford_fulkerson
void Grafo::ford_fulkerson(int s, int t){

    // Grafo residual que será alterado a cada iteração
    int **residual = new int *[nV];
    int fluxo_max = 0;

    for(int i=0;i< nV; i++) residual[i] = new int[nV];

    for (int i = 0; i < nV; i++){
        for (int j = 0; j < nV; j++){
            residual[i][j] = 0;
        }
    }

    list<intPair>::iterator j;
    
    // Realizando a cópia das capacidade de fluxo do grafo original
    for(int i = 0; i < nV; i++){
        for(j = this->adjacentes[i].begin(); j != this->adjacentes[i].end(); j++){
            residual[i][(*j).first] = (*j).second;
        }
    }

    int parente[this->nV];
    
    // Enquanto a busca em bfs do nó fonte para o sumidouro for possível
    while(bfs(residual, s, t, parente)){

        int fluxo_caminho = INT_MAX;
        
        // Será feito o caminho inverso que foi salvo no parente (de t - sumidouro até s - fonte)
        // ao executar o bfs, para saber qual foi o menor fluxo obtido
        // no caminho possível que foi retornado do bfs.
        for (int v = t; v != s; v = parente[v]) {
            int u = parente[v];
            fluxo_caminho = min(fluxo_caminho, residual[u][v]);
        }

        // A ideia nesse ponto é dada uma aresta (u,v) e a aresta (v,u), obtida do caminho em 'parente'
        // subtrair de (u,v) o fluxo mínimo obtido ao logo do caminho e somar essa quantia em (v,u)
        for (int v = t; v != s; v = parente[v]) {
            int u = parente[v];
            residual[u][v] -= fluxo_caminho;
            residual[v][u] += fluxo_caminho;
        }
        
        // O fluxo máximo será a soma dos fluxos mínimos obtidos nos caminhos possíveis
        fluxo_max += fluxo_caminho;
    }

    this->resultado = fluxo_max;
}

int main(int argc, char **argv){
    
    // Inicializando o grafo
    int n_de_vertices, n_arestas, u,v,c;

    ifstream arquivo;
    arquivo.open(argv[1]);

    arquivo >> n_de_vertices >> n_arestas;

    Grafo g(n_de_vertices);
    
    while (n_arestas--){
        arquivo >> u >> v >> c;
        g.adicionarAresta(u-1, v-1, c);
    }

    g.ford_fulkerson(0,n_de_vertices-1);
    g.imprimirResultado();
    
    return 0;
};
