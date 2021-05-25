#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <list>
using namespace std;
  
typedef pair <int, int> intPair;

// definindo a estrtutura do grafo
// sera usada matriz de adjacencia
// cada elemento da matriz sera um pair
// cada pair possuira a estrutura (vertice destino, peso)
// tambem serao usadas arestas no formato (peso(v1,v2))
class Grafo{
    int nV; // numero de vertices
    list<intPair> *adjacentes; // matriz de adjacencia
    vector< pair<int, intPair> > arestas;
    list<intPair> resultado;
    int pesoArvore;

    public:

    Grafo(int n);

    void adicionarAresta(int v1, int v2, int peso);
  
    void kruskal();

    void imprimirResultado();
};

// definindo o construtor
Grafo::Grafo(int n){ 
    this->nV = n;
    this->adjacentes = new list<intPair>[n];
}

// definindo adicao de aresta
void Grafo::adicionarAresta(int v1, int v2, int peso){
    this->adjacentes[v1].push_back(make_pair(v2,peso));
    this->adjacentes[v2].push_back(make_pair(v1,peso));
    this->arestas.push_back({peso, {v1, v2}});
}

// funcao para imprimir o resultado
void Grafo::imprimirResultado(){
    cout << "A arvore geradora minima possui seguintes arestas:" << endl;

    list<intPair>::iterator i;
    for(i = this->resultado.begin(); i != this->resultado.end(); i++){
        cout << "(" << (*i).first +1 << "," << (*i).second +1 << ")" << endl;
    }

    cout << "\nPeso da arvore geradora minima:" << endl;
    cout << this->pesoArvore << endl;
}

// union find usado para representar os conjuntos conexos
struct UnionFind{

    int *pai, *size;
    int n;
  
    // construtor
    UnionFind(int n){ 
        
        this->n = n; 
        this->pai = new int[n]; 
        this->size = new int[n];

        
        for (int i = 0; i < n; i++){
            this->size[i] = 1;
            this->pai[i] = i;
        }
    }
  
    // funcao find recursiva
    int find(int u){        
        if (u != pai[u])
            pai[u] = find(pai[u]);
        return pai[u];
    }
    
    // funcao union com heuristica de tamanhos
    // sempre adiciona a menor arvore na maior
    void _union(int x, int y){

        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot == yRoot) return;
  
        if (size[xRoot] >= size[yRoot]){
           pai[yRoot] = xRoot;

           if(size[xRoot] == size[yRoot]){
               size[xRoot] ++;
           } 
        }
        else{
            pai[xRoot] = yRoot;
        }
    }
};

// algoritmo de kruskal  
void Grafo::kruskal(){

    // inicializa o peso da arvore
    int pesoTotal = 0;

    // ordena o conjunto de arestas
    sort(arestas.begin(), arestas.end());
 
    //cria a union find para as componenetes conexas
    UnionFind uf(nV);
 
    // itera no conjunto de arestas
    vector< pair<int, intPair> >::iterator it;
    for (it=arestas.begin(); it!=arestas.end(); it++){

        int u = it->second.first; // primeiro vertice da aresta
        int v = it->second.second; // segundo vertice da aresta

        // verifica a qual componente conexa os vertices pertencem
        int componente_u = uf.find(u);
        int componente_v = uf.find(v);

        // se os vertices pertencerem a componenetes diferentes
        // significa que nao ha formacao de ciclos
        // logo adiciona-se a aresta no conjunto solucao as componenetes sao unidas
        if (componente_u != componente_v){
            pesoTotal += it->first; // incrementa o peso total da arvore
            this->resultado.push_back(make_pair(u,v)); // adiciona aresta (u,v) na solucao
            uf._union(componente_u, componente_v); // uniao das componentes
        }
    }

    this->pesoArvore = pesoTotal;  
}
  
int main(int argc, char **argv){

    int n_de_vertices, n_arestas, u,v,c;

    ifstream arquivo;
    arquivo.open(argv[1]);

    arquivo >> n_de_vertices >> n_arestas;

    Grafo g(n_de_vertices);
    
    while (n_arestas--){
        arquivo >> u >> v >> c;
        g.adicionarAresta(u-1, v-1, c);
    }
  
    g.kruskal();
    g.imprimirResultado();

    return 0;
}
