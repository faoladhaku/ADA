#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int*> llamaruta()
{
    int nruta=0;
    int nparadas=0;
    vector<int*> calificacion;
    cin>>nruta;
    for(int i=0;i<nruta;i++)
    {
        cin>>nparadas;
        int * nuevo = new int[nparadas-1];
        for(int j=0;j<nparadas-1;j++)
        {
            int dato=0;
            cin>>dato;
            nuevo[j] = dato;
        }
        calificacion.push_back(nuevo);
    }
    return calificacion;
}

void mostrar(vector<int*> chichico)
{
    for(int i =0; i<chichico.size();i++)
    {
        int j=0;
        while(chichico[i][j]!='\0')
        {
            cout<<chichico[i][j];
            j++;
        }
    }
}

int segmento_maximo(int* intereses, int inicio , int finale)
{
    int intermedio;
    int maxizquierda;
    int maxderecha;
    int max2izquierda;
    int max2derecha;
    int maxcruz;
    int suma;
    int maximo;
    if(inicio = finale)
    {
        int numero = intereses[inicio];
        return max(0,numero);
    }
    intermedio = floor((inicio+finale)/2);
    maxizquierda = segmento_maximo(intereses,inicio,intermedio);
    maxderecha = segmento_maximo(intereses,intermedio+1,finale);
    suma = intereses[intermedio];
    max2izquierda = suma;
    for(int i =intermedio-1;i<inicio;i--)
    {
        suma = suma + intereses[i];
        max2izquierda = max(max2izquierda,suma);
    }
    suma = intereses[intermedio+1];
    max2derecha = suma;
    for(int j = intermedio+2;j<finale;j++)
    {
        suma = suma + intereses[j];
        max2derecha = max(max2derecha,suma);
    }
    maxcruz = max2derecha + max2izquierda;
    maximo = max(maxcruz,maxderecha);
    maximo = max(maximo,maxizquierda);
    return maximo;
}
int main()
{
    vector<int*> prueba;
    prueba = llamaruta();
    mostrar(prueba);

}