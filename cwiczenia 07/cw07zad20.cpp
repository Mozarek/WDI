#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool check(int t[8][8] , int sum , bool row[8], int col)
{
    if(sum==0)
        return true;

    if(sum<0 || col == 8)
        return false;

    for(int i = 0; i<8;i++)
    {
        if(!row[i])// jesli jeszcze nie wzielismy niczego z tego wiersza
        {
            row[i] = true;
            if( check(t , sum - t[i][col] , row , col+1) ) return true;
            row[i] = false;
        }
        if ( check(t , sum , row , col+1) ) return true;
    }
}


int main()
{
    int tab[8][8];
    srand(time(NULL));

    for(int i =0 ;i<8; i++)
    {
        for(int j =0 ;j<8 ;j++)
        {
            tab[i][j] = rand()%10+1;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    bool rows[8];
    for(int i=0; i<8;i++)
        rows[i] = false;
    cout << check(tab , 30 , rows , 0);

    return 0;
}
// 26 zad, 30 zad, 34 zad