#include <iostream>
#define MAX 5

using namespace std;

int main()
{
    //tab [rows][columns]
    int tab[MAX][MAX] = {{24,46,8 ,20,11},
                         {2 ,4 ,14,24,35},
                         {31,24,76,90,2 },
                         {2 ,4 ,6 ,17,32},
                         {4 ,6 ,42,83,31}};

    int temp;

    //searching for column with max sum
    int maxCol;
    int maxSumCols = 0;

    for(int i=0;i<MAX;i++)
    {
        tempSum=0;
        for(int j=0 ; j<MAX ; j++)
        {
            tempSum+= tab[j][i];
        }
        if(tempSum>maxSumCols)
        {
            maxCol = i;
            maxSumCols = tempSum;
        }
    }

    //searching for row with min sum
    int minSumRows =0;
    for(int i=0;i<MAX;i++)
        minSumRows+= tab[0][i];

    int minRow = 0;

    for(int i =0;i<MAX;i++)
    {
        tempSum = 0;
        for(int j=0;j<MAX;j++)
        {
            tempSum+=tab[i][j];
        }
        if(tempSum < minSumRows)
        {
            minRow = i;
            minSumRows = tempSum;
        }
    }

    cout << "col: " << maxCol << endl;
    cout << "row: " << minRow << endl;


    return 0;
}
