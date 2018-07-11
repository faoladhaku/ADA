#include <iostream>
#include <vector>
using namespace std;

///programacion dinamica, hallar la matriz suma maxima, crear la matriz de respuestas


int sumaMaximaV(vector<int> elemento)
{
    int suma=0;
    for(int i =0;i<elemento.size();i++)
    {
        suma = suma + elemento[i];
    }
    return suma;
}

int maxima(vector<vector<int>> matriz,int filas,int columnas)
{
    int maximo =0;
    for(int i =0;i<filas;i++)
    {  
        if(maximo<sumaMaximaV(matriz[i]))
        {
            maximo = sumaMaximaV(matriz[i]);
        }
    }
    return maximo;
}

void crearM(vector<vector<int>> &matriz,int &filas,int &columnas)
{
    int elemento;
    //cin>>filas;
    //cin>>columnas;

    for(int i =0;i<filas;i++)
    {
        cin>>elemento;
        matriz[i].push_back(elemento);   
    }
}
int main()
{
    vector<vector<int>> mymatriz;
    vector<int> m1 = {1,2,3};
    vector<int> m2 = {4,5,6};
    vector<int> m3 = {7,8,9};
    mymatriz.push_back(m1);
    mymatriz.push_back(m2);
    mymatriz.push_back(m3);
    int filas,columnas=3;
    //crearM(mymatriz,filas,columnas);
    cout<<maxima(mymatriz,3,3);
}