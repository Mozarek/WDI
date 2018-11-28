#include <iostream>
#define N 6

using namespace std;

bool isPrime(int n) //pomocnicza funkcja sprawdzajaca czy liczba jest pierwsza
{
    if(n<2)
        return false;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            return false;
    }

    return true;
}

bool potnij(int tab[N] , int i)
{
    if(i==N) //jesli po ostatnim pocieciu jestesmy za tablica to oznacza ze cala tablica zostala pocieta
        return true; 
    
    int liczba = 0;

    for(int j=0; j<30 && i+j<N; j++) //tworzymy liczbe z zapisu binarnego w tablicy (pamietamy ze moze byc maksymalnie dlugosci 30)
    {
        liczba*= 2;
        liczba+= tab[i+j];

        if(isPrime(liczba) && potnij(tab, i+j+1)) //rekurencyjnie staramy sie pociac dalsza czesc
            return true;

        //jesli sie nie uda to wracamy tu i dalej tworzymy nasza liczbe z kolejnych bitow
    }

    return false;
}

int main()
{
    int tab[N] = {1,1,0,1,0,0};

    if(potnij(tab,0))
        cout << "udalo sie";
    //

    return 0;
}