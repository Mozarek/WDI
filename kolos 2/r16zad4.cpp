#include <iostream>
#define N 8
using namespace std;

struct rozwiazanie
{
    int col1;
    int col2;
};

int licz(int t[N][N] ,int w[N] , int i1 , int i2)
{
    //tu licz
}

rozwiazanie usunWieze( int t[N][N], int w[N])
{
    rozwiazanie tempR;

    int min =-1;
    int current;
    for(int i1=0 ; i1<N-1; i1++)
    {
        for(int i2=i1+1 ; i2<N ;i2++)
        {
            current = licz(t , w , i1 , i2);

            if(min==-1 || current < min)
            {
                min = current;
                tempR = {i1 , i2};
            }
        }
    }
}

int main()
{
    //
    return 0;
}