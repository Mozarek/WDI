#include <iostream>
#define MAX 5

using namespace std;

int main()
{
    //tab [rows][columns]
    int tab[MAX][MAX] = {{24,46,8,20,11},
                         {2,4,14,24,35},
                         {11,24,76,90,2},
                         {2,4,6,17,32},
                         {4,6,42,83,31}};

    bool existsRow = false;
    int temp;

    for(int i =0;i<MAX && !existsRow;i++)//iterates through rows
    {
        bool everyNum = true;
        for(int j=0; j<MAX && everyNum ;j++)//iterates through elements inside i-th row
        {
            temp = tab[i][j];

            //checks if the element contains at least one even number
            while(temp>0 && (temp%10)%2 != 0)
                temp/=10;

            if(temp==0)
                everyNum = false;
        }

        if(everyNum)
            existsRow = true;

    }


    cout << (existsRow ? "tak" : "nie");

    return 0;
}
