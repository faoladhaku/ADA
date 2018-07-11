#include <iostream>
#include <vector>
using namespace std;


void llenarsumandos(vector<int> &s1,vector<int> &s2)
{
    int tams1;
    int tams2;
    int numero;
    cout<<"cuan desea grande desea que sea el sumando 1"<<endl;
    cin>>tams1;
    cout<<"digite los numeros 1 por 1"<<endl;
    for(int i =0; i<tams1;i++)
    {
        cin>>numero;
        s1.push_back(numero);
    }
    cout<<"cuan desea grande desea que sea el sumando 2"<<endl;
    cin>>tams2;
    cout<<"digite los numeros 1 por 1"<<endl;
    for(int i =0; i<tams2;i++)
    {
        cin>>numero;
        s2.push_back(numero);
    }

}
void llenarmatriz(vector<vector<int>> &matriz,int mytam1 , int mytam2)
{
    int tamv = mytam1 + mytam2;
    for(int i = 0;i<tamv;i++)
    {
        vector<int> llenar;
        for(int j = 0; j<tamv; j++)
        {
            llenar.push_back(0); 
        }
        matriz.push_back(llenar);
    }
}
void relleno(vector<int> &a , int b)
{
    for(int i =0 ;i<b;i++)
    {
        a.push_back(0);
    }
}
void d(vector<int> s1,vector<int> s2)
{
    vector<vector<int>> matriz;
    int iguala = s1.size() + s2.size();
    int tamano = s1.size() + s2.size();
    int tamano1 = 0;
    llenarmatriz(matriz,s1.size(),s2.size());
    for(int i= 0; i<s2.size();i++)
    {
        /*if(tamano==0)
        {
            break;
        }*/
        tamano--;
        int recorrido = 0;
        for(int j = 0; j<s1.size();j++)
        {
            /*if(tamano1 == iguala)
            {
                break;
            }*/
            int numero = s2[i]*s1[j];
            int resto = numero%10;
            int n1;
            n1 = (numero-resto);
            if(n1==0)
            {
                matriz[tamano1][tamano] = resto +matriz[tamano1][tamano] + recorrido;
                recorrido = 0;
            }
            else
            {
                matriz[tamano1][tamano] = matriz[tamano1][tamano] + recorrido + numero ;
                recorrido = (numero - (numero%10))/10;
            }
            tamano1++; 
        }
        tamano1--;
    }
    cout<<"inicio m"<<endl;
    for(int i = 0 ;i<iguala;i++)
    {
        for(int j=0; j<iguala;j++)
        {
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
    cout<<"fin m"<<endl;
    vector<int> resultado;
    relleno(resultado,tamano);
    int resto=0;
    for(int i = 0;i<iguala;i++)
    {
        int resp = 0;
        int recorrido = 0;
        for(int j =0; j<iguala;j++)
        {
            resp = matriz[i][j] + resp+ resto;
        }
        int resto = resp%10;
        int nreal = resp-resto;
        if(nreal== 0)
        {
            resultado.push_back(resp);
        }
        cout<<"inserto"<<resto<<endl;
        resultado.push_back(resto);
    }

    for(int i=iguala;i>0;i--)
    {
        cout<<resultado[i]<<endl;
    }
}

int main()
{
    vector<int>s1,s2;   
    llenarsumandos(s1,s2);
    cout<<"s1"<<endl;
    for(int i =0; i< s1.size();i++)
    {
        cout<<s1[i]<<endl;
    }
    cout<<"s2"<<endl;
    for(int i =0; i< s1.size();i++)
    {
        cout<<s1[i]<<endl;
    }
    cout<<"respuesta"<<endl;
    d(s1,s2);
    /*vector<int> ala = d(s1,s2);
    for(int i = 0; i<ala.size();i++)
    {
        cout<<ala[i]<<endl;
    }*/
    /*vector<vector<int>> a;
    cout<<"matriz"<<endl;
    llenarmatriz(a,2,2);
    cout<<a.size();
    */

    /*for(int i =0;i<a.size();i++)
    {
        for(int j= 0;j<a[i].size();i++)
        {
            cout<<a[i][j];
        }
    }*/
}