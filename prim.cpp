// incluindo funcionalidades da biblioteca padrao
# include <iostream>
# include <vector>
# include <queue>
# include <utility>
# include <list>
# include <iterator>
using namespace std;
#define infinito 9999999999999
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
    vector<int> resultado;
    vector<int> pesos;

    public:

    Grafo(int n);

    void adicionarAresta(int v1, int v2, int peso);

    void prim();

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
    cout << "A arvore geradora minima possui seguintes arestas:" << endl;
    
    int pesoTotal = 0;
    for(int i = 0; i < this->nV; i++){
        if(this->resultado[i] != -1){
            pesoTotal += this->pesos[i];
            cout << "(" << resultado[i] << "," << i << ")" << endl;
        }
    }

    cout << "\nPeso da arvore geradora minima:" << endl;
        cout << pesoTotal << endl;
}

// definindo o algoritmo de Prim
void Grafo::prim(){

    // inicializa o vetor de custos
    vector<int> custo(this->nV, infinito);

    // inicializa o vetor de vertice anterior
    vector<int> anterior(this->nV, -1);

    // por padrao o vertice de origem sera o primeiro
    int origem = 0;

    // inicializa o custo da origem como 0
    custo[origem] = 0;

    // por padrao as filas de prioridade sao heaps em C++
    //cria heap minima ordenada pelos pesos dos vertices
    priority_queue<intPair,vector<intPair>,greater<intPair>> heapMin; 

    // cria vetor que indica se um vertice esta na arvore ou nao
    vector<bool> pertence(this->nV, false);

    // adiciona a origem na heap
    heapMin.push(make_pair(custo[origem],origem));

    // contador para a quantidade de vertices ja visitados
    int visitados = 0;

    // enquanto a heap nao estiver vazia continua o loop
    while(!heapMin.empty() && visitados < this->nV){
        
        // seleciona o vertice de menor custo
        intPair elemento = heapMin.top();
        int v = elemento.second;

        // retira o elemento selecionado acima da heap
        heapMin.pop();

        //checa se v ja esta na arvore
        if(pertence[v]){
            continue; // caso esteja pula o vertice repetido
        }

        pertence[v] = true;

        visitados ++;

        // itera sobre a lista de adjacentes de v
        list<intPair>::iterator i;
        for(i = this->adjacentes[v].begin(); i != this->adjacentes[v].end(); i++){
            
            // le os valores do elemento da lista
            int vizinho = (*i).first;
            int peso = (*i).second;

            // se o vizinho nao estiver na arvore e o peso encontrado for menor que
            // o peso que esta no vetor de custo adiciona (peso,vizinho) na heap
            // e altera o vertice anterior do vizinho para ser v
            if(!pertence[vizinho] && custo[vizinho]>peso){
                custo[vizinho] = peso;
                heapMin.push(make_pair(peso,vizinho));
                anterior[vizinho] = v;
            }
        }
    }

    this->resultado = anterior;
    this->pesos = custo;
}

int main(){
    int n_de_vertices = 9;
    
    Grafo g(n_de_vertices);
 
    g.adicionarAresta(0, 1, 4);
    g.adicionarAresta(0, 7, 8);
    g.adicionarAresta(1, 2, 8);
    g.adicionarAresta(1, 7, 11);
    g.adicionarAresta(2, 3, 7);
    g.adicionarAresta(2, 8, 2);
    g.adicionarAresta(2, 5, 4);
    g.adicionarAresta(3, 4, 9);
    g.adicionarAresta(3, 5, 14);
    g.adicionarAresta(4, 5, 10);
    g.adicionarAresta(5, 6, 2);
    g.adicionarAresta(6, 7, 1);
    g.adicionarAresta(6, 8, 6);
    g.adicionarAresta(7, 8, 7);
 
    g.prim();
    g.imprimirResultado();

    return 0;
};