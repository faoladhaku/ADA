#include <limits>
#include <vector>
#define infinity std::numeric_limits<int>::max()
#include <iostream>
using namespace std;

void Warshall(int **Adj_Matrix, int vertices){

int i,j,k;

for(k = 0; k < vertices; k++)
    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            if(Adj_Matrix[i][j] > (Adj_Matrix[i][k] + Adj_Matrix[k][j]))
                   Adj_Matrix[i][j] = Adj_Matrix[i][k]+Adj_Matrix[k][j];       
}

class nodo{
    public:
    int peso;
    nodo* siguiente ;
    private:
    nodo();

};
nodo::nodo()
{
    this->peso=0;
    this->siguiente=0;
}
class arista{
    public:
    nodo* elemento1;
    nodo* elemento2;
    int peso;
    private:
    arista(nodo* elemento1,nodo* elemento2, int peso);
    //void add_arista(nodo elemento1,nodo elemento2,int peso);
};
arista::arista(nodo* elemento1,nodo* elemento2,int peso)
{
    this->peso =peso;
    this->elemento1=elemento1;
    this->elemento2=elemento2;
}
class grafo{
    public:
    vector<nodo*> vecinos;
    vector<arista*> aristas; 
    private:
    void warshall();
    void new_arista(arista* nueva);
};
void grafo::new_arista(arista* nueva)
{
    this->aristas.push_back(nueva);
};
void grafo::warshall()
{
    for()
}
int main(){

int vertices;
cin>>vertices;
int matriz[vertices][vertices];
for(int i=0;i<vertices;i++)
{
    for(int j=0;j<vertices;j++)
    {
        matriz[i][j] =0;
    }
}
int ganador;
cin>>ganador;
int timer;
cin>>timer;

int elemento1;
int elemento2;
int peso;
for(int i =0;i<vertices;i++)
{
    
}

int i,j,NumofVertices;//num vertices primera linea
int **Adj_Matrix;
int *Cost_Row;
int celda_ganadora;//segunda linea
int timer;//tercera linea
//cuarta linea elemento1 elemento2 peso hasta tener todo el grafo lleno
//grafo direccional 
std::cout<<"Enter the number of vertices: ";
std::cin>>NumofVertices;

Adj_Matrix = new int*[NumofVertices];

for(i = 0;i < NumofVertices; i++){
    Adj_Matrix[i] = new int[NumofVertices];
}

std::cout<<"Enter the adjacency matrix"<<std::endl;
    for(i = 0; i < NumofVertices; i++){
        for(j = 0; j < NumofVertices; j++){
            std::cin>> Adj_Matrix[i][j];
            if (Adj_Matrix[i][j] == 0 && i != j)
            {
                Adj_Matrix[i][j] = infinity;
            }
    }
}

Warshall(Adj_Matrix,NumofVertices);
for(i = 0; i < NumofVertices; i++){
    for(j = 0; j < NumofVertices; j++){
            std::cout<<"Shortest path between "<<i<<" and "<<j<<" is : ";
            if(Adj_Matrix[i][j]==infinity)
                    std::cout<<"INF"<<std::endl;
            else
                    std::cout<<Adj_Matrix[i][j]<<std::endl;
    }
}

return 0;

}