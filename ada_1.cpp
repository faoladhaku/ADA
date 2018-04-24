#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;
double insert_sort(int* myvector,int tam)
{
    unsigned t0,t1;
    t0 = clock();
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
    t1 = clock();
    double mytime = (double(t1-t0)/CLOCKS_PER_SEC);
    return mytime;
}

double bubble_sort(int* myvector, int tam)
{
    unsigned t0,t1;
    t0 = clock();
    for(int i =0;i+1<tam;i++)
    {
        for(int j =0;j+1<=tam;j++)
        {
            if(myvector[j]>=myvector[j+1])
            {
                int aux = myvector[j+1];
                myvector[j+1] = myvector[j];
                myvector[j] = aux;
            }
        }
    }
    t1 = clock();
    double mytime = (double(t1-t0)/CLOCKS_PER_SEC);
    return mytime;
}
int* merging_sort(int* myarray1,int* myarray2,int mysize1,int mysize2)
{
    int* mytrue_result = new int[mysize1+mysize2];
    int i =0;
    int y =0;
    int contador=0;
    while(mysize1!=0 && mysize2!=0)
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
        
    }
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
        /*for(int k =0; k<tam;k++)
        {
            if(trabajador[k]<=trabajador1[k])
            {
                myvector[k] = trabajador[k];
            }
            myvector[k] = trabajador1[k];
        }*/
        /*if(trabajador[divididor1] <= trabajador1[0])
        {
            for(int i =0;i<divididor1;i++)
            {
                myvector[i] = trabajador[i];
            }
            for(int i=divididor1; i<tam;i++)
            {
                myvector[i] = trabajador1[i-divididor1];
            }
            cout<<"asd";
            return myvector;
        }*/
        int* myresult= merging_sort(trabajador,trabajador1,divididor1,divididor2);
        //cout<<"cuack";
        return myresult;
    }
}
double merge_sort_with_time(int* array,int tamano)
{
    unsigned t0,t1;
    double mytime;
    t0=clock();
    merge_sort(array,tamano);
    t1=clock();
    mytime = (double(t1-t0)/CLOCKS_PER_SEC);
    return mytime;
}
int main()
{
    const int tamano = 20;
    int prueba[tamano] = {2,3,5,2,1,1,2,3,4,9,12,13,15,21,52,64,23,41,20,21};
    double tiempo_insert_sort = insert_sort(prueba,tamano);
    /*int* ordenado = insert_sort(prueba,tamano);
    for(int i=0;i<tamano;i++)
    {
        cout<<ordenado[i]<<endl;
    }
    */
    //cout<<tiempo_insert_sort<<endl;
    const int tamano2 = 5;
    int prueba2[tamano2] ={9,5,7,3,1};
    double tiempo_bubble_sort = bubble_sort(prueba2,tamano2);
    /*int* ordenado2 = bubble_sort(prueba2,tamano);
    for(int i=0;i<tamano;i++)
    {
        cout<<ordenado2[i]<<endl;
    } */   
    const int tamano3 = 7;
    int prueba3[tamano3] = {3,5,1,6,4,2,7};
    int* prueba4 = merge_sort(prueba3,tamano3);
    /*for(int i =0; i<tamano3;i++)
    {
        cout<<prueba4[i];
    }*/
    int entrante[1] = {1};
    int* prueba5 = merge_sort(entrante,1);
    //double merge_time = merge_sort_with_time(prueba3,tamano3);
    //cout<<merge_time<<endl;
    //cout<<tiempo_bubble_sort<<endl;
    //cout<<prueba4[1];
    ifstream mispruebas;
    ofstream tiempos;
    mispruebas.open("pruebas.txt",ios::in);
    tiempos.open("tiempos.csv");
    int mytamano = 1;
    double mytime1;
    double mytime2;
    double mytime3;
    unsigned t0,t1;
    while(!mispruebas.eof())
    {
        
        char* mispruebas1=new char[mytamano];
        mispruebas>>mispruebas1;
        //cout<<mispruebas1<<endl;
        int* prueba_definitava=new int[mytamano];
        for(int i=0;i<mytamano;i++)
        {
            prueba_definitava[i] = mispruebas1[i] - '0';
        }
        mytime1 = insert_sort(prueba_definitava,mytamano);
        mytime2 = bubble_sort(prueba_definitava,mytamano);
        //t0 = clock();
        mytime3 = merge_sort_with_time(prueba_definitava,mytamano);
        //int* medidor = merge_sort(prueba_definitava,mytamano);
        //for(int i=0;i<mytamano;i++)
        //{
        //    cout<<medidor[i];
        //}
        //t1= clock();
        //mytime3 = (double(t1-t0)/CLOCKS_PER_SEC);
        tiempos<<mytime1;
        //tiempos<<";";
        //tiempos<<mytamano;
        tiempos<<";";
        tiempos<<mytime2;
        tiempos<<";";
        //tiempos<<mytamano;
        tiempos<<mytime3;
        tiempos<<endl;
        //cout<<mytime1<<endl;
        mytamano++;
        //delete mispruebas1;
        //delete prueba_definitava;
    }
    
    return 0;
}