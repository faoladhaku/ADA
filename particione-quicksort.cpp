#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <cmath>
using namespace std;

vector<int> creav(int tam)
{
    int random;
    vector<int> prueba;
    for(int j=0;j<tam;j++)
    {
        random=rand()%100+1;
        prueba.push_back(random);
    }
    return prueba;
}

int particione(vector<int>& arreglo,int p, int r,int& contador)
{
    int x = arreglo[r];
    int i = p-1;
    for(int j = p; j<=r-1;j++)
    {
        if(arreglo[j] <= x)
        {
            i++;
            /*int aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;*/
            swap(arreglo[i],arreglo[j]);
            contador++;
        }
    }
    /*int aux2 = arreglo[i+1];
    arreglo[i+1] = arreglo[r];
    arreglo[r] = aux2;*/
    swap(arreglo[i+1],arreglo[r]);
    contador++;
    return i+1;
}

/*int busqueda(vector<int>& arreglo, int indice)
{
    int indicador = particione(arreglo,0,arreglo.size()-1);
    if(indice<=indicador)
    {
        while(indice<indicador)
        {
            arreglo.erase(arreglo.begin()+indicador,arreglo.end());
            indicador= particione(arreglo,0,arreglo.size()-1);
        }
        return arreglo[indicador];
    }
    while(indicador<indice)
        {
            arreglo.erase(arreglo.begin(),arreglo.begin()+indicador);
            indicador= particione(arreglo,0,arreglo.size()-1);
        }
    return arreglo[indicador];
}
*/
void quicksort(vector<int>& practica, int inicio, int myfinal,int & contador)
{
    if(inicio<myfinal)
    {
        int q = particione(practica,inicio,myfinal,contador);
        quicksort(practica,inicio,q-1,contador);
        quicksort(practica,q+1,myfinal,contador);
    }
}
int main()
{
    //int random;
    
    srand(time(NULL));
    vector<int> partion = {99,33,55,77,11,22,88,66,33,44};

    vector<int> hola = {10,9,8,7,6,5,4,3,2,1};
    /*cout<<particione(partion,0,partion.size()-1);
    for(int i =0; i<partion.size();i++)
    {
        cout<<partion[i]<<" ";
    }
    cout<<busqueda(partion,3);
    quicksort(partion,0,9);
    for(int i =0; i<partion.size();i++)
    {
        cout<<partion[i]<<"elemento"<<endl;
    }*/
    vector<int> resultados;
    for(int i =0;i<10;i++)
    {
        int contador=0;
        int numvector= 256;
        vector<int> prueba;
        for(int j=0;j<numvector;j++)
        {  
            prueba= creav(numvector);
            
        }
        //cout<<prueba.size()<<endl;
        quicksort(prueba,0,prueba.size()-1,contador);
        resultados.push_back(contador);
        numvector++;
    }
    float average=0;
    for(int i =0;i<resultados.size();i++)
    {
        average = average + resultados[i];
    }
    average = average / 10.00;
    float primero = 256*log(256);
    float segundo = 256*log10(256);
    cout<<"el logaritmo en base e "<<primero<<endl;
    cout<<"el logaritmo en base 10 "<<segundo<<endl;
    cout<<"el promedio "<<average<<endl;
    return 0;
}