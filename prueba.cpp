#include <iostream>
#include <time.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > matriz(int potencia, vector<vector<int>> mymatriz)
{
    if(potencia ==1)
    {
        return mymatriz;
    }
    vector<vector<int> > resultado={{0,0},{0,0}};
    for(int i=0;i<1;i++)
        {
            for(int j=0 ;j<1;j++)
            {
                resultado[i][j] += mymatriz[i][j] * mymatriz[j][i];
            }
        }
}

vector<vector<int> > fibodivven(int numero)
{
    vector<vector<int> > mymatriz={{1,1},{1,0}};
    vector<vector<int> > r=matriz(numero,mymatriz);
    return r;
}

int main()
{
    cout<<"a";
    vector<vector<int> > r = fibodivven(3);
    return 0;
}