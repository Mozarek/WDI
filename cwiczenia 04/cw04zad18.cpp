#include <iostream>
#define MAX 5

using namespace std;

int najwSuma(int tab[MAX][MAX])
{
    int maxSum = tab[0][0];//inicjujemy maxSum suma podciagu jednoelementowego 

    int sumRow;
    int sumCol;

    for(int len = 1 ; len <=10 ; len++)//sprawdzamy osobno podciagi dla roznych dlugosci (z zad wiemy ze maks 10)
    {
        for(int rowcol = 0 ; rowcol < MAX && len <= MAX; rowcol++)//rownoczesnie szukamy pionowych i poziomych
        {
            sumRow=0;
            sumCol=0;
            int i;
            for(i=0;i<len;i++)//liczymy sume pierwszych len elementow w kolumnie/wierszu
            {
                sumCol+=tab[i][rowcol];
                sumRow+=tab[rowcol][i];
            }

            //jesli suma jest wieksza niz maksymalna -> update
            if(sumCol>maxSum)
                maxSum = sumCol;

            if(sumRow>maxSum)
                maxSum = sumRow;

            //kolejno 'przesuwamy' nasza sume dodajac kolejny element i odejmujac pierwszy z naszego podciagu
            for(;i<MAX;i++)
            {
                sumCol = sumCol - tab[i-len][rowcol] + tab[i][rowcol];
                sumRow = sumRow - tab[rowcol][i-len] + tab[rowcol][i];

                if(sumCol>maxSum)
                    maxSum = sumCol;

                if(sumRow>maxSum)
                    maxSum = sumRow;
            }
        }
    }

    return maxSum;
}

int main()
{

    int tab[MAX][MAX] = {{-6,4,2,2,7},
                         {2,-5,7,5,-4},
                         {6,6,-4,2,13},
                         {9,5,3,-2,87},
                         {8,3,2,3,-7}};
    //

    cout << najwSuma(tab);
    return 0;
}