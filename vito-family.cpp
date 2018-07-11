#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int particione(vector<long long>& arreglo,int p, int r)
{
    int x = arreglo[r];
    int i = p-1;
    for(int j = p; j<=r-1;j++)
    {
        if(arreglo[j] <= x)
        {
            i++;
            long long aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
        }
    }
    long long aux2 = arreglo[i+1];
    arreglo[i+1] = arreglo[r];
    arreglo[r] = aux2;
    return i+1;
}

void ordenap(vector<long long>& myvector)
{
    for(int i =myvector.size()-1;i>0;i--)
    {
        particione(myvector,0,i);
    }
    
    
}

int vito(vector<long long>& myvector)
{
    ordenap(myvector);
    int pivote=myvector[myvector.size()/2];
    long long suma =0;
    for(int i =0;i<myvector.size();i++)
    {
        suma = suma + abs(pivote - myvector[i]);
    }
    return suma;
}

int main()
{
    int ncasos=0;
    int nvecinos=0;
    long long variable;
    vector<long long> resultados;
    cin>>ncasos;
    while(ncasos)
    {
        cin>>nvecinos;
        vector<long long> A;
        while(nvecinos) 
        {
            cin>>variable;
            A.push_back(variable);
            nvecinos--;
            
        }
        resultados.push_back(vito(A));
        ncasos--;
    }
    for(int i =0;i<resultados.size();i++)
    {
        cout<<resultados[i]<<endl;
    }
    return 0;
}