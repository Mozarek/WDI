#include <iostream>
#include <iomanip>
#define MAX 5

int ilePrzyjaciol(int tab[MAX][MAX])
{
    //dla kazdego elementu tablicy sprawdzamy z jakiego zbioru liczb sie sklada
    //i zapisujemy w nowej tablicy ktora dla kazdej naszej liczby przechowuje binarna reprezentacje danego zbioru cyfr

    int countOfFriends = 0;

    int tabBinarnyZbior[MAX][MAX];

    bool tabCyfr[10];

    int tempLiczba;
    int tempBin;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<10;k++)
                tabCyfr[k] = false;
            //zerowanie tabCYfr

            tempLiczba = tab[i][j];
            
            while(tempLiczba>0)
            {
                tabCyfr[tempLiczba%10] = true;
                tempLiczba/=10;
            }

            tempBin = 0;

            for(int k=0;k<10;k++)
            {
                tempBin*= 2;
                tempBin+= tabCyfr[k];
            }

            tabBinarnyZbior[i][j] = tempBin;
                
        }
    }

    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            //jesli z kazdej strony dana liczba ma albo sasiada z takim samym zbiorem cyfr albo nie ma w ogole sasiada
            if( (i+1 >= MAX || tabBinarnyZbior[i+1][j] == tabBinarnyZbior[i][j]) &&
                (j+1 >= MAX || tabBinarnyZbior[i][j+1] == tabBinarnyZbior[i][j]) &&
                (i-1 < 0 || tabBinarnyZbior[i-1][j] == tabBinarnyZbior[i][j]) &&
                (j-1 < 0 || tabBinarnyZbior[i+1][j] == tabBinarnyZbior[i][j]) )
                countOfFriends++;

        }

    }

    return countOfFriends;
}

int main()
{
    int tab[MAX][MAX] = {{0  ,2  ,4  ,7  ,8  },
                         {5  ,0  ,9  ,10 ,10 },
                         {112,21 ,0  ,4  ,6  },
                         {221,122,212,0  ,9  },
                         {211,12 ,7  ,8  ,0  }};
    //
    std::cout << ilePrzyjaciol(tab);


    return 0;
}