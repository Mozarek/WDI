#include <iostream>
#define MAX 5

using namespace std;

bool atLeastOnePrimeDigit(int n)
{
    while(n>0)
    {
        if(n%10 == 2 || n%10 == 3 || n%10 == 5 || n%10 == 7)
            return true;
        
        n/=10;
    }

    return false;
}

bool rowWithAllNumbersWithPrimeDigit(int tab[MAX][MAX])
{
    for(int row=0 ; row<MAX ; row++)
    {
        bool everyNumber = true;

        for(int col=0; col<MAX && everyNumber;col++)
        {
            if(!atLeastOnePrimeDigit(tab[row][col]))
                everyNumber = false;
        }

        if(everyNumber)
            return true;

    }


    return false;
}

int main()
{
    int tab[MAX][MAX] = {{64,45,23,27,78},
                         {21,54,78,53,48},
                         {64,68,47,28,32},
                         {94,55,33,22,77},
                         {89,33,22,35,70}};

    if(rowWithAllNumbersWithPrimeDigit(tab))
        cout << "istnieje";
    else
        cout << "nie istnieje";
    return 0;
}