#include <iostream>
#include <vector>
using namespace std;

void swap()
{
    int iteraciones;
    int longitud;
    int dato;
    vector<int*> trenes;
    cin>>iteraciones;
    for(int i =0;i<iteraciones;i++)
    {
        cin>>longitud;
        while(i<longitud)
        {
            cin>>dato;
            int* tren = new int[longitud];
            tren[i] = dato;
            trenes.push_back(tren);
            i++;
        }
    }
    while(iteraciones)
    {
        for(int i=0;;i++)
        {
            trenes[i][i];     
        }
        iteraciones--;
    }
}

int main()
{
    swap();

    return 0;
}