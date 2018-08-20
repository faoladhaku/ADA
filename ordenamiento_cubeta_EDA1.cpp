#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

class nodo()
{
public:
    int dato;
    
};


int main()
{
    vector<int> aux = {64,8,216,512,27,729,0,1,343,125};
    vector< vector<int> > cubeta(aux.size(), vector<int>(aux.size()));
    for(int i =0;i<aux.size();i++)
    {
       int ordenar = aux[i]%10;
       /*for(int j=0;j<aux.size();i++)
       {
           cubeta[ordenar][0].push_back(ordenar);
       }
       
       cout<<cubeta[6][0];*/
    }
    return 0;
}
