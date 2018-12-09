#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 4

using namespace std;

int tab[N][N];

bool inRange(int y, int x)
{
    return (x<N && y<N);
}

bool possibleMove(int from , int to)
{
    while(to>=10)
        to/=10;

    return (from%10 < to);

}

bool kingMove(int y, int x)
{
    if(x== N-1 && y== N-1)
        return true;

    if( inRange(y+1,x) && possibleMove(tab[y][x] , tab[y+1][x]) && kingMove(y+1,x))
        return true;

    if( inRange(y,x+1) && possibleMove(tab[y][x] , tab[y][x+1]) && kingMove(y,x+1))
        return true;

    if( inRange(y+1,x+1) && possibleMove(tab[y][x] , tab[y+1][x+1]) && kingMove(y+1,x))
        return true;

    return false;
}

int main()
{
    srand(time(NULL));

    for(int i =0;i<N;i++){
        for(int j =0; j<N;j++)
        {
            tab[i][j] = rand()%100+1;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    //
    cout << ( kingMove(0,0) ? "tak" : "nie" );

    return 0;
}