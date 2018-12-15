#include <iostream>
#define N 6

using namespace std;


using namespace std;

bool podzbiory(int t[N] , int sumA ,int sumB ,int elA, int elB, int i)
{
    if(elA>0 && sumA==sumB && elA==elB)
        return true;
    
    if(i==N)
        return false;

    if( podzbiory(t , sumA , sumB , elA , elB ,i+1) ||
        podzbiory(t , sumA+t[i] , sumB , elA+1 , elB ,i+1) ||
        podzbiory(t , sumA , sumB+t[i] , elA , elB+1 ,i+1) )
        return true;

    return false;
}

bool zadanie(int t[N])
{
    return podzbiory(t ,0,0,0,0,0);
}

int main()
{
    int tablicu[N] = {1,3 ,5 , 7 , 70, 200};

    cout << zadanie(tablicu);

    return 0; 
}