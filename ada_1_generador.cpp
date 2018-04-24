#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    
    /*char hola[]= "1234";
    int tamano;
    int tam[4];
    for(int idx =0;idx<4;idx++)
    {
        tam[idx] = hola[idx] - '0';
    }
    for(int i =0 ;i<4;i++)
    {
        cout<<tam[i]<<endl;
    }*/
    //int a[3] = "{1,2,3}";
    int numero_pruebas = 101;
    ofstream pruebas;
    pruebas.open("pruebas.txt");
    for(int i =0;i<numero_pruebas;i++)
    {
        for(int j=1;j<=i;j++)
        {
            pruebas<<j;
        }
        pruebas<<endl;
    }
    pruebas.close();
   /* char* hola = "123";
    int* tam;
    for(int idx =0;idx<3;idx++)
    {
        tam[idx] = hola[idx] - '0';
    }
    for(int i =0 ;i<3;i++)
    {
        cout<<tam[i]<<endl;
    }

    hola = "1234";
    int* tam;
    for(int idx =0;idx<4;idx++)
    {
        tam[idx] = hola[idx] - '0';
    }
      for(int i =0 ;i<4;i++)
    {
        cout<<tam[i]<<endl;
    }
    */
   /* int i =1;
    int mytama[i];
    return 0;*/
}