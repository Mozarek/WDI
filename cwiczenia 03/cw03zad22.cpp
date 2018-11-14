#include <iostream>

using namespace std;

const int N =10;

int maxIncSeq(int tab[N])
{
    int maxLen = 0;

    int Len = 1;
    int sumInd = 0;
    int sumWart = tab[0];//liczymy początkowe wartosci dla i=0;

    for(int i =1 ;i<N ;i++)//sprawdzamy od i=1 porownujac z poprzednimi wyrazami ciagu
    {
        if(sumInd==sumWart)
            if(Len > maxLen)
                maxLen = Len;
        //

        if(tab[i] > tab[i-1])//jesli jest nadal rosnacy to zwiekszamy dlugosc i odopwiednio sumy
        {
            Len++;
            sumInd+=i;
            sumWart+=tab[i];
        }
        else//w przeciwnym wypadku zaczynamy szukac kolejnego rosnacego podciagu
        {
            Len=1;
            sumInd = i;
            sumWart = tab[i];
        }
    }

    if(sumInd==sumWart)//konieczne dodatkowe sprawdzenie jesli podciag bylby rosnacy az do konca wyjsciowego ciagu
            if(Len > maxLen)
                maxLen = Len;

    return maxLen;
}

int main()
{
    int tab[N] = {0,1,0,3,1,6,8,3,2,3};

    cout << maxIncSeq(tab);

    return 0;
}