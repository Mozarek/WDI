#include <iostream>
#define NUMER 10


using namespace std;

int main()
{

    int tab[NUMER];//tablica 10 najwiekszych elementów

    for(int i =0;i<NUMER;i++)//zerowanie tablicy
        tab[i] = 0;

    int liczba;
    int j;
    while(cin >> liczba && liczba !=0)//wczytujemy kolejne liczby aż do natrafienia na 0
    {
        j = NUMER;

        while(j>0 && liczba > tab[j-1])//znajdujemy miejsce
            j--;

        for(int i = NUMER - 1; i>j;i--)//przesuwamy wszystkie mniejsze elementy do tyłu
            tab[i] = tab[i-1];

        tab[j] = liczba;//wstawiamy nową liczbę
    }

    cout << tab[NUMER-1];

    return 0;
}
