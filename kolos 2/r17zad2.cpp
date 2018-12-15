#include <iostream>

using namespace std;

void wypisz(int tab[9])// funkcja wypisujaca
{
    for(int i =0;i<9;i++)
        cout << tab[i] << " ";

    cout << endl;

    return;
}

bool pierwsza[9] = {0,1,1,0,1,0,1,0,0}; // element o indeksie i oznacza czy liczba i+1 jest pierwsza

void perm(int tab[9], int i , bool wyk[9])
{
    if(i==9)// jesli doszlismy za tablice to wypisz aktualna permutacje
    {
        wypisz(tab);
        return;
    }

    // szukamy liczby (j+1) ktora mozemy wpisac na i-te miejsce w tablicy tab
    // zaczynamy szukac od 2 bo 1 już jest umiejscowione na samym poczatku
    for(int j=1 ; j<9 ; j++)
    {
        if( !wyk[j] && // liczba nie została wykorzystana jeszcze
            (!pierwsza[j] || !pierwsza[tab[i-1] -1]) && // nie mogą sąsiadować dwie liczby pierwsze
            (j+1 - tab[i-1] > 1 || j+1 - tab[i-1] < -1) ) // roznica miedzy dwoma kolejnymi wieksza od 1
            {
                tab[i] = j+1;
                wyk[j] = true;
                perm(tab , i+1 , wyk);
                wyk[j] = false;
            }
    }

    return;
}

int main()
{
    int tab[9] = {1,0,0,0,0,0,0,0,0};
    bool wyk[9]= {1,0,0,0,0,0,0,0,0};

    perm(tab , 1 , wyk);

    return 0;
}