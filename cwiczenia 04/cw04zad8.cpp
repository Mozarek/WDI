#include <iostream>
#define MAX 5

using namespace std;

struct odpowiedz
{
    bool czy;
    int dlugosc;
};

odpowiedz geometrycznyPodciag(int tab[MAX][MAX])
{
    odpowiedz Answer = {false, 0};

    int x,y;
    for(int xp = 0; xp< MAX-2; xp++)
    {
        for(int yp = 0; yp<MAX-2; yp++)
        {
            x = xp;
            y = yp;
            int tempdl = 0;
            if(tab[y][x]*tab[y+2][x+2] == tab[y+1][x+1]*tab[y+1][x+1])
            {
                Answer.czy = true;
                tempdl = 3;
                x++;
                y++;
            }

            while(x<MAX-3 && y < MAX-3 && tab[y][x]*tab[y+2][x+2] == tab[y+1][x+1]*tab[y+1][x+1])
            {
                tempdl++;
                x++;
                y++;
            }

            if(tempdl > Answer.dlugosc)
                Answer.dlugosc = tempdl;

        }
    }

    return Answer;
}


int main()
{

    int tab[MAX][MAX] = {{3,2,4,7,8},
                         {5,5,9,10,10},
                         {1,2,25,4,6},
                         {5,5,4,15,9},
                         {1,3,7,8,9}};

    odpowiedz A = geometrycznyPodciag(tab);
    cout << (A.czy ? "tak" : "nie") << endl;
    cout << "dlugosc: " << A.dlugosc;

    return 0;
}
