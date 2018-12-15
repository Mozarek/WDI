#include <iostream>
#define N 8
using namespace std;

void poprawneSumy(int t1[N] , int t2[N] , int i , int suma[2*N] , int j , int ValSuma)
{
    if(i==N)
    {
        for(int k=0;k<j-1;k++)
            cout << suma[k] << "+";
        cout << suma[j-1] << endl;

        return;
    }

    suma[j] = t1[i];
    poprawneSumy(t1,t2 , i+1 , suma , j+1 , ValSuma + t1[i]);
    if(t1[j] != t2[j])
    {
        suma[j] = t2[i];
        poprawneSumy(t1,t2 , i+1 , suma , j+1 , ValSuma + t2[i]);
    }

    suma[j] = t1[i];
    suma[j+1] = t2[i];
    poprawneSumy(t1,t2 , i+1 , suma , j+2 , ValSuma + t1[i] + t2[i]);

    return;
}


void rozw(int t1[N], int t2[N])
{
    int suma[2*N];
    poprawneSumy(t1,t2,0, suma,0,0);
}

int main()
{

    //
    return 0;
}