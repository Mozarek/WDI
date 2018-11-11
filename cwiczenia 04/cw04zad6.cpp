#include <iostream>
#define MAX 5
using namespace std;

void przepisz(int t1[MAX][MAX] , int t2[MAX])
{
    int tabCol[MAX];
    for(int i=0 ;i<MAX; i++)
        tabCol[i] = 0;

    int minimum;
    int jT2 = 0;
    int row;
    bool singleton;
    bool endCond;


    do
    {
        //szukamy pierwszego elementu (takiego którego indeks miesci sie w zakresie)
        row = 0;
        while(tabCol[row] >= MAX)
            row++;

        //szukamy minimalnego elementu
        minimum = t1[row][tabCol[row]];

        int lastRow = row;

        for(row= row+1 ; row<MAX ; row++)
        {
            if(tabCol[row] < MAX)
            {
                if(t1[row][tabCol[row]] <= minimum)
                {
                    minimum = t1[row][tabCol[row]];
                    lastRow = row;
                }
            }
        }


        //dla znalezionego minimum szukamy wszystkie wystapienia
        singleton = true;
        tabCol[lastRow]++;
        for(row = lastRow-1; row>=0 ; row--)
        {
            //przesuwamy wszystkie tabCol[row] wskazujace na wartosci minimalne w prawo
            if(t1[row][tabCol[row]] == minimum)
            {
                tabCol[row]++;
                singleton = false;
            }
        }

        //jesli singleton to wpisz do t2;
        if(singleton)
        {
            t2[jT2] = minimum;
            jT2++;
        }

        //sprawdzamy warunek konca
        endCond = true;
        for(row=0;row<MAX;row++)
        {
            if(tabCol[row]<MAX)
            {
                endCond = false;
                break;
            }
        }
    }while(!endCond);

    //pozostale miejsca w t2 wypelniamy zerami
    for(;jT2<MAX;jT2++)
        t2[jT2] = 0;

    return;
}

int main()
{
    int tab[MAX][MAX] = {{1,2,4,6,8},
                         {2,5,9,10,11},
                         {1,2,3,4,6},
                         {5,6,7,8,9},
                         {1,3,7,8,9}};

    int t2[MAX];

    przepisz(tab , t2);

    for(int i =0;i<MAX;i++)
        std::cout << t2[i] << " ";

    return 0;
}
