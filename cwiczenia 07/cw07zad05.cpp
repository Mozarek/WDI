#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#define N 8

using namespace std;

int deltaX[8] = {-2,-2,-1,-1,1,1,2,2};
int deltaY[8] = {1,-1,2,-2,2,-2,1,-1};

bool inRange(int x, int y) //pomocnicza funkcja sprawdzajaca czy skok jest mozliwy
{
    return (x>=0 && x<N && y>=0 && y<N);
}

bool skoczek(int x, int y, int count, int tab[N][N])
{
    tab[y][x] = count; //wpisujemy w pole na ktore skoczylismy numer skoku

    if(count == 64) //jesli juz obskoczylismy wszystkie to koniec
        return true;

    for(int i=0;i<8;i++) //kazdy skok z mozliwych 8 sprawdzamy
    {
        if( inRange(x+deltaX[i] , y+deltaY[i]) && //jesli jest wewnatrz tablicy NxN
            tab[y+deltaY[i]][x+deltaX[i]] == 0 && //jesli pole juz nie zostalo odwiedzone
            skoczek(x+deltaX[i] , y+deltaY[i] , count+1 , tab) ) //skok na to miejsce
            return true;
    }

    tab[y][x] = 0; //jesli nie byl mozliwy zaden skok to cofamy ten aktualny

    return false;
}

int main()
{
    int tab[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            tab[i][j] = 0;
    //

    if(skoczek(0,0,1,tab))
        cout << "Udalo sie" << endl << endl;
    //

    //fancy animacja
    for(int max=1 ; max<=N*N ; max++)
    {
        system( "cls" );
        //wypisz aktualna tablice z liczbami mniejszymi od max
        for(int y=0;y<N;y++)
        {
            for(int x=0;x<N;x++)
            {
                if(tab[y][x]<=max)
                    cout << setw(2) << tab[y][x] << " ";
                else
                    cout << "   ";
            }
            cout << endl;
        }

        Sleep(600);
        
    }
    

    return 0;
}