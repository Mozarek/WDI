#include <iostream>
#define MAX 5


using namespace std;

int main()
{
    //tab [rows][columns]
    int tab[MAX][MAX] = {{24,46,8,20,11},
                         {2,4,14,24,35},
                         {31,24,76,90,2},
                         {2,4,6,17,32},
                         {4,6,42,83,31}};

    int temp;
    bool everyRow = true;
    for(int i = 0;i<MAX && everyRow;i++) //iterates through rows
    {
        bool oddNumberInRow = false;
        for(int j =0;j<MAX && !oddNumberInRow;j++) //iterates through elements of row #i
        {
            temp = tab[i][j];

            //checks if the element consists only of odd numbers
            while(temp>0 && (temp%10)%2 == 1)
            {
                temp/=10;
            }

            if(temp == 0)
                oddNumberInRow = true;
        }

        if(!oddNumberInRow)
            everyRow = false;
    }


    cout << (everyRow ? "tak" : "nie");

    return 0;
}
