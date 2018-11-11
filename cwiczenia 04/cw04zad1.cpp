#include <iostream>
#define MAX 20

using namespace std;

int main()
{
    int tab[MAX][MAX];
    int wypelnienie = 1;

    for(int i =0; i*2 < MAX;i++)
    {
        int x =i;
        int y =i;

        for(; x<MAX-i ; x++)
            tab[x][y] = wypelnienie++;
        x--;

        for(; y+1<MAX-i; y++)
            tab[x][y+1] = wypelnienie++;

        for(; x-1>= i;x--)
            tab[x-1][y] = wypelnienie++;

        for(; y-1>i;y--)
            tab[x][y-1] = wypelnienie++;
    }

    //wypisywanie
    for(int y=0;y<MAX;y++)
    {
        for(int x = 0; x<MAX;x++)
            cout << tab[x][y] << " ";
        cout << endl;
    }
    return 0;
}
