// incluindo funcionalidades da biblioteca padrao
# include <iostream>
# include <fstream>
# include <vector>
# include <queue>
# include <utility>
# include <list>
# include <iterator>
using namespace std;
#define infinito 999999999
typedef pair<int,int> intPair;

// definindo a estrtutura do grafo
// sera usada matriz de adjacencia
// cada elemento da matriz sera um pair
// cada pair possuira a estrutura (vertice destino, peso)
// tambem serao usadas arestas no formato (peso(v1,v2))
class Grafo{
    int nV; // numero de vertices
    list<intPair> *adjacentes; // matriz de adjacencia
    vector< pair<int, intPair> > arestas; //arestas
    int origem;
    vector<int> distancias;

    public:

    Grafo(int n);

    void adicionarAresta(int v1, int v2, int peso);

    void dijkstra(int origem);

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

// funcao que imprime o resultado do algoritmo
void Grafo::imprimirResultado(){
    cout << "Distancias minimas a partir da origem" << endl;
    cout << "Vertice de origem: " << this->origem +1 << endl;
    
    for(int i = 0; i < this->nV; i++){
        if(i != this->origem){
            cout << "Destino: " << i+1 << " ---- Distancia minima: " << this->distancias[i] << endl;
        }
    }
}

// definindo o algoritmo de Prim
void Grafo::dijkstra(int origem){

    // inicializa o vetor de distancias
    vector<int> distancia(this->nV, infinito);

    // inicializa o custo da origem como 0
    distancia[origem] = 0;

    // por padrao as filas de prioridade sao heaps em C++
    //cria heap minima ordenada pelos pesos dos vertices
    priority_queue<intPair,vector<intPair>,greater<intPair>> heapMin; 

    // cria vetor que indica se um vertice esta na arvore ou nao
    vector<bool> visitado(this->nV, false);

    // adiciona a origem na heap
    heapMin.push(make_pair(distancia[origem],origem));

    // contador de vertices visitados
    int quantidade_visitados = 0;

    // enquanto a heap n estiver vazia continua o loop
    while(!heapMin.empty() && quantidade_visitados < this->nV){
        
        // seleciona o vertice de menor custo
        intPair elemento = heapMin.top();
        int v = elemento.second;

        // retira o elemento selecionado acima da heap
        heapMin.pop();

        //checa se v ja foi visitado
        if(visitado[v]){
            continue; // se sim pula o vertice repetido
        }

        visitado[v] = true;
        quantidade_visitados ++;

        // itera sobre a lista de adjacentes de v
        list<intPair>::iterator i;
        for(i = this->adjacentes[v].begin(); i != this->adjacentes[v].end(); i++){
            
            // le os valores do elemento da lista
            int vizinho = (*i).first;
            int peso = (*i).second;

            
            if(!visitado[vizinho] && distancia[vizinho]>distancia[v]+peso){
                distancia[vizinho] = distancia[v]+peso;
                heapMin.push(make_pair(distancia[vizinho],vizinho));
            }
        }
    }

    this->distancias = distancia;
    this->origem = origem;
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

    g.dijkstra(0);
    g.imprimirResultado();

    return 0;
};
