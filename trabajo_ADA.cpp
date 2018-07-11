#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void generador(int npruebas,char* nombre_archivo)
{
    int numero_pruebas = npruebas;
    int numero_aleatorio;
    srand(time(NULL));
    ofstream pruebas;
    pruebas.open(nombre_archivo);
    for(int i=0;i<numero_pruebas;i++)
    {
        for(int j=0;j<=i;j++)
        {
            pruebas<<1+rand()%(10-1);            
        }
        if(i == numero_pruebas-1)
        {
            break;
        }
        pruebas<<endl;
    }
    pruebas.close();
}
int* merging_sort(int* myarray1,int* myarray2,int mysize1,int mysize2)
{
    int* mytrue_result = new int[mysize1+mysize2+1];
    int inicio =0;
    int medio = mysize1-1;
    int finale = mysize1+mysize2-1;
    for(int i = inicio; i<medio-1;i++)
    {
        mytrue_result[i] = myarray1[i];
    }
    int reinicio=0;
    for(int j = medio;j<finale-1;j++)
    {
        mytrue_result[j] = myarray2[reinicio];
        reinicio++;
    }
    int elemento1 = 0;
    int elemento2 = 0;
    int corredor = 0;
    while(mysize1!=0 && mysize2!=0)
    {
        if(myarray1[elemento1]<=myarray2[elemento2])
        {
            mytrue_result[corredor] = myarray1[elemento1];
            elemento1++;
            mysize1--;
            corredor++;
        }
        else
        {
            mytrue_result[corredor] = myarray2[elemento2];
            elemento2++;
            mysize2--;
            corredor++;
        }
    }
    int quedante = 0;
    if(mysize1>1)
    {
        while(mysize1!=0)
        {
            
            mytrue_result[corredor] = myarray1[elemento1];
            mysize1--;
            elemento1++;
            corredor++;
        }
    }
    if(mysize2>1)
    {
        while(mysize2!=0)
        {
            mytrue_result[corredor] = myarray2[elemento2];
            mysize2--;
            elemento2++;
            corredor++;
        }
    }
    return mytrue_result;
}

int* merge_sort(int* myvector, int inicio, int tam)
{
    
    if(tam-inicio<2)
    {
        return myvector;
    }    
    else
    {
        int divididor1 = floor(tam/2);
        int divididor2 = tam-divididor1;
        int* trabajador = new int[divididor1];
        for(int i = 0;i<divididor1;i++)
        {
            trabajador[i] = myvector[i];
        }
        int* trabajador1 = new int[divididor2];
        for(int j = divididor1;j<tam;j++)
        {
            trabajador1[j-divididor1] = myvector[j];
        }
        
        trabajador = merge_sort(trabajador,inicio,divididor1-1);
        trabajador1 =merge_sort(trabajador1,divididor1-1,divididor2);
        int* myresult= merging_sort(trabajador,trabajador1,divididor1-1,divididor2-1);
        return myresult;
    }
}

int* insert_sort(int* myvector,int tam)
{
    for(int i=0;i+1<tam;i++)
    {
        if(myvector[i+1] <= myvector[i])
        {
            int posicion_guardada = i;
            int aux = myvector[i+1];
            myvector[i+1] = myvector[i];
            myvector[i] = aux;
            
            for(int j=i-1;j>=0;j--)
            {
                if(myvector[i] < myvector[j])
                {
                    aux = myvector[i];
                    myvector[i] = myvector[j];
                    myvector[j] = aux;
                }
                i = i-1;
            }
            i = posicion_guardada;
        }
    }
    return myvector;
}
int* intercala(int* myvector,int inicio, int intermedio,int myfinal)
{
    int* auxiliar = new int[myfinal+1];
    for(int i = inicio; i<intermedio;i++)
    {
        auxiliar[i] = myvector[i];
    }
    int retrocede = myfinal-1;
    for(int j = intermedio; j<myfinal; j++)
    {
        auxiliar[retrocede] = myvector[j];
        retrocede--;
    }

    int inicio1 = inicio;
    int myfinal1 = myfinal-1;
    for(int k = 0; k<myfinal;k++)
    {
        if(auxiliar[inicio1]<=auxiliar[myfinal1])
        {
            myvector[k] = auxiliar[inicio1];
            inicio1++;
        }
        else
        {
            myvector[k] = auxiliar[myfinal1];
            myfinal1--;
        }
    }
    return myvector;
}

int* merge_hibrido_insert(int* myvector,int inicio,int tam)
{
    if(tam-inicio <= 64)
    {
        insert_sort(myvector,tam);
    }
    else
    {
        int intermedio = floor(tam/2);
        //cout<<"1"<<endl;
        merge_hibrido_insert(myvector,inicio,intermedio-1);
        merge_hibrido_insert(myvector,intermedio+1,tam);
        int* resultado = new int[tam];
        resultado = intercala(myvector,inicio,intermedio,tam);
        return resultado;
    }
}
/*int* merge_hibrido_quick(int* myvector,int inicio,int tam)
{
    if(tam-inicio <= 64)
    {
        vector<int> ordena = (myvector,myvector+tam);
        sort(ordena.begin(),ordena.end());
        for(int i=0;i<tam;i++)
        {
            myvector[i] = ordena[i];
        }
    }
    else
    {
        int intermedio = floor(tam/2);
        //cout<<"1"<<endl;
        merge_hibrido_insert(myvector,inicio,intermedio-1);
        merge_hibrido_insert(myvector,intermedio+1,tam);
        int* resultado = new int[tam];
        resultado = intercala(myvector,inicio,intermedio,tam);
        return resultado;
    }
}*/
int main()
{
    char* nombre_prueba = "pruebas1.txt";
    char* nombre_resultados = "resultados1.txt";
    int vector_tamano = 1;
    double tiempo1,tiempo2;
    unsigned t1,t2,t3,t4;
    generador(70,nombre_prueba);
    /*int hola[11] = {2,3,4,5,1,7,10,12,15,21,8};
    int* ordenado = merge_sort(hola,11);
    for(int i =0;i<11;i++)
    {
        cout<<ordenado[i]<<endl;
    }*/
    ifstream mispruebas;
    ofstream tiempos;
    mispruebas.open(nombre_prueba,ios::in);
    tiempos.open(nombre_resultados);
    while(!mispruebas.eof())
    {
        char* mispruebas1=new char[vector_tamano];
        mispruebas>>mispruebas1;
        //cout<<mispruebas1<<endl;
        int* prueba_definitiva=new int[vector_tamano];
        for(int i=0;i<vector_tamano;i++)
        {
            prueba_definitiva[i] = mispruebas1[i] - '0';
        }
        /*
        for(int i=0;i<vector_tamano;i++)
        {
            cout<<prueba_definitiva[i]<<endl;
        }
        */
        t1 = clock(); 
        merge_sort(prueba_definitiva,0,vector_tamano);
        t2 = clock();
        tiempo1 = (double(t2-t1)/CLOCKS_PER_SEC);
        /*
        prueba_definitiva = merge_sort(prueba_definitiva,vector_tamano);
        for(int i=0;i<vector_tamano;i++)
        {
            cout<<prueba_definitiva[i]<<endl;
        }
        */

        t3 = clock();
        merge_hibrido_insert(prueba_definitiva,0,vector_tamano);
        t4 = clock();
        tiempo2 = (double(t4-t3)/CLOCKS_PER_SEC);
        
        /*prueba_definitiva = merge_hibrido_insert(prueba_definitiva,0,vector_tamano);
        for(int i=0;i<vector_tamano;i++)
        {
            cout<<prueba_definitiva[i]<<endl;
        }*/
        
        
        tiempos<<tiempo1;
        tiempos<<";";
        tiempos<<tiempo2;
        tiempos<<endl;

        vector_tamano++;
    }
}