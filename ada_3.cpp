#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int* merging_sort(int* myarray1,int* myarray2,int mysize1,int mysize2)
{
    int* mytrue_result = new int[mysize1+mysize2];
    //cout<<mysize1+mysize2<<endl;
    /*int i =0;
    int y =0;
    int contador=0;*/
    /*cout<<"array1"<<endl;
    for(int i=0;i<mysize1;i++)
    {
        cout<<myarray1[i]<<endl;
    }
    cout<<"array2"<<endl;
    for(int i=0;i<mysize1;i++)
    {
        cout<<myarray2[i]<<endl;
    }
    cout<<"acaban"<<endl;*/
    /*while(mysize1!=0 && mysize2!=0)
    {
        if(myarray1[i] <= myarray2[y])
        {
            mytrue_result[contador] = myarray1[i];
            i++;
            mysize1--;
            contador++;
        }
        else
        {
            mytrue_result[contador] = myarray2[y];
            y++;
            contador++;
            mysize2--;
        }
        
    }*/
    /*
    if(mysize1>0)
    {
        while(mysize1!=0)
        {
            mytrue_result[contador] = myarray1[i];
            mysize1--;
            contador++;
        }
    }
    if(mysize2>0)
    {
        while(mysize2!=0)
        {
            mytrue_result[contador] = myarray2[y];
            mysize2--;
            contador++;
        }
    }
    */
    int inicio =0;
    int medio = mysize1;
    int finale = mysize1+mysize2;
    for(int i = inicio; i<medio;i++)
    {
        mytrue_result[i] = myarray1[i];
    }
    int reinicio=0;
    for(int j = medio;j<finale;j++)
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
    //cout<<mysize1<<"tamaño1"<<endl;
    //cout<<mysize2<<"tamaño2"<<endl;
    int quedante = 0;
    if(mysize1>0)
    {
        //quedante = finale - ;
        while(mysize1!=0)
        {
            
            mytrue_result[corredor] = myarray1[elemento1];
            mysize1--;
            elemento1++;
            corredor++;
        }
        /*for(int i = mysize1;i>0;i--)
        {
            corredor++;
            mytrue_result[corredor] = myarray1[elemento1]
        }*/
    }
    if(mysize2>0)
    {
        while(mysize2!=0)
        {
            //corredor++;
            mytrue_result[corredor] = myarray2[elemento2];
            mysize2--;
            elemento2++;
            corredor++;
        }
    }
    return mytrue_result;
}

int* merge_sort(int* myvector, int tam)
{
    
    if(tam<=1)
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
            //cout<<trabajador[i]<<endl;
        }
        int* trabajador1 = new int[divididor2];
        for(int j = divididor1;j<tam;j++)
        {
            trabajador1[j-divididor1] = myvector[j];
            //cout<<trabajador1[j-divididor1];
        }
        
        trabajador = merge_sort(trabajador,divididor1);
        trabajador1 =merge_sort(trabajador1,divididor2);
        int* myresult= merging_sort(trabajador,trabajador1,divididor1,divididor2);
        return myresult;
    }
}


int* newmerge(int* myarray1,int* myarray2,int mysize1,int mysize2)
{
    int* mytrue_result = new int[mysize1+mysize2];
    
    int inicio =0;
    int medio = mysize1;
    int finale = mysize1+mysize2;
    for(int i = inicio; i<medio;i++)
    {
        mytrue_result[i] = myarray1[i];
    }
    int reinicio=0;
    for(int j = medio;j<finale;j++)
    {
        mytrue_result[j] = myarray2[reinicio];
        reinicio++;
    }
    
    /*int elemento1 = 0;
    int elemento2 = mysize2;
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
            elemento2--;
            mysize2--;
            corredor++;
        }
    }
/*
    if(mysize1>0)
    {
        while(mysize1!=0)
        {
            
            mytrue_result[corredor] = myarray1[elemento1];
            mysize1--;
            elemento1++;
            corredor++;
        }
    }
    if(mysize2>0)
    {
        while(mysize2!=0)
        {
            //corredor++;
            mytrue_result[corredor] = myarray2[elemento2];
            mysize2--;
            elemento2++;
            corredor++;
        }
    }*/
    return mytrue_result;
}

int* clasesmerge(int* myvector,int tam)
{
       if(tam<=1)
    {
        return myvector;
    }    
    else
    {
        int divididor1 = floor(tam/2);
        int divididor2 = tam-divididor1;
        int* trabajador = new int[divididor1];
        //cout<<"empiezo"<<endl;
        for(int i = 0;i<divididor1;i++)
        {
            trabajador[i] = myvector[i];
            //cout<<trabajador[i]<<endl;
        }
        //cout<<"termino"<<endl;
        int* trabajador1 = new int[divididor2];
        for(int j = divididor1;j<tam;j++)
        {
            trabajador1[j-divididor1] = myvector[j];
            //cout<<trabajador1[j-divididor1];
        }
        
        trabajador = clasesmerge(trabajador,divididor1);
        trabajador1 =clasesmerge(trabajador1,divididor2);
        
        int* aux = new int[divididor2];
        for(int i =0;i<divididor2;i++)
        {
            aux[i] = trabajador1[divididor2-i-1];
        }
        //cout<<"separacion2"<<endl;
        /*for(int i =0;i<divididor1;i++)
        {
            cout<<trabajador[i]<<endl;
        }
        cout<<"separacion"<<endl;
        for(int i =0;i<divididor2;i++)
        {
            cout<<trabajador1[i]<<endl;
        }*/
        int* myresult= newmerge(trabajador,trabajador1,divididor1,divididor2);
        return myresult;
    }
    
}

int main()
{
    int hola[6] = {2,3,4,5,1,7};
    /*int* ordenado = merge_sort(hola,6);
    for(int i =0;i<6;i++)
    {
        cout<<ordenado[i]<<endl;
    }*/
    int* tarea = clasesmerge(hola,6);
    for(int i =0;i<6;i++)
    {
        cout<<tarea[i]<<endl;
    }
}