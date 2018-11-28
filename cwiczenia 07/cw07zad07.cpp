#include <iostream>
#define N 6

using namespace std;

void sumIndVal( int tab[N] , int i , int sumVal, int sumInd, int elements, int &min_elements, int &bestSum)
{
    if(elements>0 && sumVal==sumInd && elements < min_elements)
    {
        bestSum = sumVal;
        min_elements = elements;
        return;
    }

    if(i==N)
        return;

    sumIndVal(tab , i+1 , sumVal+tab[i] , sumInd+i , elements+1 , min_elements , bestSum);
    sumIndVal(tab , i+1 , sumVal , sumInd , elements , min_elements , bestSum);
}

int task(int tab[N])
{
    int min_el = N+1;
    int suma = -1;

    sumIndVal(tab, 0, 0, 0, 0 , min_el ,suma);

    return suma;
}

int main()
{

    int tab[N] = {1,7,3,5,11,2};

    cout << task(tab);

    return 0;
}