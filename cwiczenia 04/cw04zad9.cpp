#include <iostream>
#define MAX 5

using namespace std;

struct odpowiedz
{
    bool czyIstnieje;
    int x;
    int y;

    odpowiedz(bool b, int xs, int ys){czyIstnieje = b; x=xs; y=ys;};
};

odpowiedz szukajKwadratu(int tab[MAX][MAX] , int k)
{
    int bok = 2; // prawdziwa dlugosc boku = bok+1

    for(int xp=0; xp<MAX-2; xp++)
    {
        for(int yp=0; yp<MAX-2; yp++)
        {
            //szukamy kwadratu
            bok=2;
            while(xp+bok<MAX && yp+bok<MAX)
            {
                if(tab[yp][xp] * tab[yp+bok][xp] * tab[yp][xp+bok] * tab[yp+bok][xp+bok] == k)
                    return odpowiedz(true, xp+bok/2 , yp+bok/2);

                bok+=2;
            }
        }
    }

    return odpowiedz(false, -1, -1);
}

int main()
{
    int tab[MAX][MAX] = {{3,2,4,7,8},
                         {5,5,9,10,10},
                         {1,2,25,4,6},
                         {5,5,4,15,9},
                         {1,3,7,8,9}};

    odpowiedz naszKwadrat = szukajKwadratu(tab , 175);

    cout << (naszKwadrat.czyIstnieje ? "tak" : "nie") <<endl;
    cout << "X: " << naszKwadrat.x << endl;
    cout << "Y: " << naszKwadrat.y << endl;
    return 0;
}
