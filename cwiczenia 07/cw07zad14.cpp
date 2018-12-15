#include <iostream>
#define N 8


using namespace std;

// zbior hetmanow reprezentujemy jako ciag numerow wierszy dla hetmanow znajdujacych sie w
// kolejnych kolumnach tj. t[kolumna] == wiersz

bool possible(int col, int row, int tab[])
{
    for(int i = 0; i<col ; i++)
    {
        if( tab[i] == row || (col - i) == (row - tab[i]) || (col - i) == (tab[i] - row) )
            return false;
    }

    return true;

}

void write(int tab[])
{
    for(int i =0;i<N;i++)
        cout << tab[i];

    cout << endl;
}

void hetman(int col , int tab[])
{
    if(col == N)// doszlismy do konca (mamy gotowe ustawienie)
    {
        //wypisz
        write(tab);
        return;
    }

    //sprawdz kazdy mozliwy wiersz w nastepnej kolumnie
    for(int row=0; row<N ; row++)
    {
        if( possible(col, row, tab) )//jesli nowy hetman nie bedzie sie z poprzednimi bił
        {
            tab[col] = row;//wstawiamy go tam
            hetman(col+1 , tab);//rekurencyjnie wstawiamy kolejnych
        }
    }

    return;
}

int main()
{
    int tab[N];

    for(int i=0;i<N;i++)
        tab[i] = -1;

    hetman(0,tab);

    return 0;
}