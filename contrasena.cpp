#include <iostream>
#include <string>
#include <vector>

using namespace std;

class bloque
{
    public:
    vector<vector<string>> bloques;
    int nbloques;
    vector<int> tamanos;
    bloque();
    void anadir(vector<string> bloque);

};
bloque::bloque()
{
    this->nbloques=0;
}

void myordena(vector<string>& cadena)
{
    int nswaps=0;
    for(int k =0;k<cadena.size();k++)
    {
        for(int i =0;i<cadena[k].size()-1;i++)
        {
            for(int j =i+1;j<cadena[k].size();j++)
            {
                if(cadena[i][i]>cadena[i][j])
                {
                    nswaps++;
                } 
                /*if(a[i]>a[j])
                {
                    cout<<"raro"<<a[i]<<"separa"<<a[j]<<endl;
                }
                if(a[i]<a[j])
                {
                    cout<<"normal?"<<endl;
                }
                */
                //nswaps++;
            }
        }
    }
    cout<<nswaps<<"swaps"<<endl;
}

void begin()
{
    int tamano;
    int lineas;
    int niteraciones;
    bloque bloques;
    vector<string> letras;
    string palabra;
    cin>>niteraciones;
    cout<<endl;
    for(int i=0;i<niteraciones;i++)
    {
        cin>>tamano;
        cin>>lineas;
        for(int i=0;i<lineas;i++)
        {
            cin>>palabra;
            letras.push_back(palabra);
        }
        cout<<endl;
        
    }
    myordena(letras);
    for(int i=0;i<letras.size();i++)
    {
        cout<<letras[i];
    }
}
int main()
{
    begin();
}