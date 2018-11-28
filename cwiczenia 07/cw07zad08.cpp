#include <iostream>

using namespace std;

void hop(int t[8][8], int y, int x, int currentCost, int &bestCost)
{
    if(y == 8)
    {
        if(currentCost < bestCost)
            bestCost = currentCost;

        return;
    }

    if(x>0)
        hop(t , y+1 , x-1 , currentCost+t[y][x] , bestCost);
    if(x<7)
        hop(t , y+1 , x+1 , currentCost+t[y][x] , bestCost);

    hop(t , y+1 , x , currentCost+t[y][x] , bestCost);

    return;
}


int minimumCost(int t[8][8], int column)
{
    int bestCost = 0;
    for(int i=0;i<8;i++)
        bestCost+=t[i][column]; //liczymy koszt po lini prostej zeby miec z czym porownywac
    //
    hop(t , 0 , column , 0 , bestCost);

    return bestCost;
}

int main()
{
    int tab[8][8];

    //losowanie i wypisanie tablicy
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            tab[i][j] = rand()%10+1;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
            
    //

    cout << minimumCost(tab , 0);
    return 0;
}