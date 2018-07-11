#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

double max(vector<int> numero,int tamano)
{
    double contador = 0;
    int maximo =0;
    for(int i=0;i<tamano;i++)
    {
        if(numero[i] >maximo)
        {
            maximo = numero[i];   
            contador++;
        }
    }
    return contador;
}

vector<int> generador()
{
    
    int potencia = 8;
    int oka;
    int num;
    int promedio;
    vector<int> promedios;
    srand(time(NULL));
    for(int i =0; i<13;i++)
    {
        for(int i =0;i<100;i++)
        {
            
            vector<int> numeros;
            oka = pow(2,potencia);
            for(int j =0;j<oka;j++)
            {
                num=1+rand()%(INT_MAX);
                numeros.push_back(num);
            }
            promedio =max(numeros,oka) + promedio;
            cout<<numeros.size()<<"size"<<endl;
        }
        promedio = promedio/100;
        promedios.push_back(promedio);
        promedio =0;
        //numeros.clear();
        potencia++;
    }
    return promedios;
}

int main()
{   
    vector<int> pro;
    pro = generador();
    for(int i=1;i<pro.size();i++)
    {
        cout<<pro[i]<<endl;
    }
    return 0;
}