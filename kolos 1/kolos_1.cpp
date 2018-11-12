#include <iostream>

const int N = 10;

int ilePodciagow(int tab[N])
{
    int poczatek = 0;
    int poprzedniaWartosc = tab[0];
    int najdluzszy = 0;
    int sumInd = 0;
    int sumWart = tab[0];

    for(int i =1;i<N ;i++)
    {
        //sprawdzamy czy znaleziony ma okreslone wlasnosci
        if(sumWart == sumInd)
        {
            if(i-poczatek > najdluzszy)
                najdluzszy = i - poczatek;
        }

        if(poprzedniaWartosc < tab[i])
        {
            sumInd+=i;
            sumWart+=tab[i];
        }
        else
        {
            //szukamy kolejnego spojnego podciagu
            sumInd = i;
            sumWart = tab[i];
            poczatek = i;
        }
        poprzedniaWartosc = tab[i];
    }

    return najdluzszy;
}

int main()
{
    int tab[N] = {1,0,1,5,5,3,7,12,13,5};

    std::cout << ilePodciagow(tab);

    return 0;
}