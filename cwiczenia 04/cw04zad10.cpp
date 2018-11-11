#include <iostream>
#define MAX 5

using namespace std;

bool allZeros(int tab[MAX][MAX])
{
    bool answer = true;

    bool ZerosInCols[MAX];
    for(int i =0;i<MAX;i++)
        ZerosInCols[i] = false;

    
    for(int row =0; row<MAX && answer; row++)
    {
        bool zeroInRow = false;
        for(int col =0; col<MAX && !zeroInRow; col++)
        {
            if(tab[row][col] ==0)
            {
                zeroInRow = true;
                ZerosInCols[col] = true;
            }
        }

            answer = zeroInRow;
    }

        for(int i =0;i<MAX && answer;i++)
        {
            if(!ZerosInCols[i])
                answer = false;
        }

    return answer;
}

int main()
{
    int tab[MAX][MAX] = {{0,2,4,7,8},
                         {5,0,9,10,10},
                         {1,2,0,4,6},
                         {5,5,4,0,9},
                         {1,3,7,8,0}};

    std::cout << (allZeros(tab) ? "same zera" : "nie");
    return 0;
}
