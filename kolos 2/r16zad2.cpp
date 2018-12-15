#include <iostream>
#define N 6

using namespace std;

struct polozenieWiez
{
    int row1;
    int col1;
    int row2;
    int col2;
};

int sumRow[N];
int sumCol[N];

void init(int tab[N][N])
{
    for(int i=0;i<N;i++)
    {
        sumRow[i]=0;
        sumCol[i]=0;
        for(int j=0;j<N;j++)
        {
            sumRow[i]+= tab[i][j];
            sumCol[i]+= tab[j][i];
        }
    }
}

int gain(polozenieWiez p , int tab[N][N])
{
    if(p.row1==p.row2)
    {
        return tab[p.row1][p.col1] + sumCol[p.col2] - tab[p.row2][p.col2];
    }else if(p.col1==p.col2)
    {
        return tab[p.row1][p.col1] + sumRow[p.row2] - tab[p.row2][p.col2];
    }else
    {
        return sumRow[p.row2] + sumCol[p.col2] - 2*tab[p.row2][p.col2] - tab[p.row1][p.col2] - tab[p.row2][p.col1];
    }
}

polozenieWiez maxSum(int tab[N][N])
{
    polozenieWiez tempP;

    int maximum = -1;

    int size = N*N;

    for(int i = 0 ; i< size-1 ;i++)
    {
        int row1 = i/N; int col1 = i%N;
        int sum = sumRow[row1] + sumCol[col1] - 2*tab[row1][col1];

        for(int j =i+1;j<size ;j++)
        {
            int row2 = j/N; int col2 = j%N;
            int total = sum + gain({row1,col1 , row2,col2} , tab);
            if(total>maximum)
            {
                maximum = total;
                tempP ={ row1,col1 , row2,col2};
            }
        }
    }

    return tempP;
}

int main()
{
    int tab[N][N];

    init(tab);
    polozenieWiez wynik = maxSum(tab);

    return 0;
}