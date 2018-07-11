#include <iostream>
#include <time.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;


int fibo(int numero)
{
    if(numero==0)
    {
        return 0;
    }
    if(numero==1)
    {
        return 1;
    }
    return fibo(numero-1) + fibo(numero-2);
}
int fiborec(int numero)
{
    int a=0;
    int b=1;
    int resultado;
    if(numero == 0)
    {
        return 0;
    }
    if(numero == 1)
    {
        return 1;
    }
    int contador = numero +2;
    while(contador>=0)
    {
        resultado = a+b;
        contador--;
    }
}

int fiborecv(int numero)
{
    vector<double> iterativo;
    if(numero ==0)
    {
        return 0;
    }
    if(numero ==1)
    {
        return 1;
    } 
    iterativo.push_back(0);
    iterativo.push_back(1);
    //cout<<"llege"<<endl;
    for(int i = 2;i<=numero;i++)
    {

        iterativo.push_back(iterativo[i-1] + iterativo[i-2]);
        //cout<<iterativo[i];
    }
    return iterativo[numero];
}
int fiborecv2(int numero)
{
    int numero1 = 0;
    int numero2 = 1;
    int numero3;
    int i =1;
    while(i <numero)
    {

        numero3 =fmod(numero1,pow(2,20)) + fmod(numero2,pow(2,20));
        numero1 = numero2;
        numero2 = numero3;
        i++;
    }
    return fmod(numero3,pow(2,20));
}

vector<vector<int> > matriz(int potencia, vector<vector<int>> mymatriz)
{
    cout<<"s";
    if(potencia ==1)
    {
        return mymatriz;
    }
    vector<vector<int>> resultado={{0,0},{0,0}};
    int contador = potencia-1;
    /*while(contador>0)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0 ;j<2;j++)
            {
                resultado[i][j] += mymatriz[i][j] * mymatriz[j][i];
            }
        }
        contador--;
    }*/
    cout<<"a";
    for(int i=0;i<2;i++)
        {
            for(int j=0 ;j<2;j++)
            {
                cout<<mymatriz[i][j]<<"ele";
                resultado[i][j] += mymatriz[i][j] * mymatriz[j][i];
            }
        }
}/*
vector<vector<int> > crossmatriz(vector<vector<int> > m1,vector<vector<int> > m2)
{
    vector<vector<int> > resultado;
    for(int i=0;i<m1.size();i++)
    {
        for(int j=0 ;j<m1[i].size();j++)
        {
            resultado[i][j] += m1[i][j] * m2[i][j];
        }
    }
}*/
vector<vector<int> > fibodivven(int numero)
{
    vector<vector<int> > mymatriz={{1,1},{1,0}};
    /*vector<int> linea1;
    linea1.push_back(1);
    linea1.push_back(1);
    vector<int> linea2;
    linea2.push_back(1);
    linea2.push_back(0);
    mymatriz.push_back(linea1);
    mymatriz.push_back(linea2);*/
    /*vector<int*> mymatriz;
    int fila1[2] = {1,1};
    int fila2[2] = {1,0};
    mymatriz.push_back(fila1);
    mymatriz.push_back(fila2);*/
    //int divide1 = floor(numero/2);
    //int divide2 = numero - divide1;
    //la primera mitad de la potencia
    vector<vector<int> > r=matriz(numero,mymatriz);
    //la segunda mitad de la potencia
    //vector<vector<int> > arriba=matriz(divide2,mymatriz);
    //retorna la matriz multiplicada
    //return crossmatriz(abajo,arriba);
    return r;
}

int main()
{
    /*double maxtest = 10000;
    int maxfib = 100;
    double numero_aleatorio;
    srand(time(NULL));*/
    //cout<<fibo(8)<<endl;
    /*for(int i=1;i<maxtest;i++)
    {
        numero_aleatorio = 1+rand()%(maxfib-1);
        cout<<fiborecv(numero_aleatorio)<<endl;
    }*/
    //cout<<fiborecv(4)<<endl;
    cout<<"d";
    vector<vector<int> > resultado = fibodivven(4); 
    /*for(int i=0;i<resultado.size();i++)
    {
        for(int j=0 ;j<resultado[i].size();j++)
        {
            cout<<resultado[i][j]<<endl;
        }
        cout<<endl;
    }*/
    return 0;
}