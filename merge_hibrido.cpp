#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

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
    if(tam-inicio <= 4)
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

int* merging_sort(int* myarray1,int* myarray2,int inicio,int intermedio,int tam)
{
    int* resultado = new int[tam+1];
    int inicio1 = inicio;
    int inicio2 = inicio;
    int inicio3 = inicio;
    int intermedio1 = intermedio;

    while(inicio1 != intermedio && intermedio1 != tam)
    {
        if(myarray1[inicio1]<= myarray2[intermedio1])
        {
            resultado[inicio1] = myarray1[inicio2];
            inicio1++;
            inicio2++;
        }
        else
        {
            resultado[inicio1] = myarray2[inicio3];
            inicio1++;
            inicio3++;
            intermedio1++;
        }
    }
    while(inicio1!= intermedio)
    {
        resultado[inicio1] = myarray1[inicio2];
        inicio1++;
    }
    while(intermedio1!= tam)
    {
        resultado[inicio1] = myarray2[inicio3];
        inicio1++;
        inicio3++;
        intermedio1++;
    }
    return resultado;
}

int* merge_sort(int* myvector, int inicio, int tam)
{
    
    if(tam-inicio<2)
    {
        return myvector;
    }    
    else
    {
        int intermedio = floor(tam/2);
        int* izquierda = new int[intermedio];
        int* derecha = new int[tam-intermedio];
        for(int i = inicio;i<intermedio;i++)
        {
            izquierda[i] = myvector[i];
        }
        for(int j = intermedio;j<tam;j++)
        {
            derecha[j] = myvector[j];
        }
        izquierda=merge_sort(izquierda,inicio,intermedio);
        derecha=merge_sort(derecha,intermedio,tam);
        int* myresult= merging_sort(izquierda,derecha,inicio,intermedio,tam);
        return myresult;
    }
}
int main()
{
    int prueba[6] = {1,5,4,3,2,6};
    int pruebaa[3] = {5,3,1};
    /*int* prueba1 = insert_sort(prueba,6);
    for(int i =0;i<6;i++)
    {
       cout<<prueba1[i]<<endl;
    }
    int* prueba1 = merge_hibrido_insert(prueba,0,6);
    int* prueba2 = merge_hibrido_insert(pruebaa,0,3);
    //cout<<prueba[1];
    */
   int * prueba1  = merge_sort(prueba,0,6);
   for(int i =0; i<6;i++)
   {
       cout<<prueba1[i]<<endl;
   }
}