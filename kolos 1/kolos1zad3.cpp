#include <iostream>
#define MAX 10

using namespace std;

int main()
{
    int tab[MAX];

    for(int i =0;i<MAX;i++)
        tab[i] = rand()%1000 + 1;
    //inicjujemy tablice pseudolosowymi liczbami z zakresu [1, 1000]


    int top10[10];

    for(int i =0 ; i<10;i++)
        top10[i] = 0;
    //pomocnicza tablica przechowujaca 10 najwiekszych liczb posortowanych rosnaco

    int j;
    for(int i =0;i<MAX;i++)
    {
        j=-1;
        while(j+1<10 && tab[i] > top10[j+1])//wyznaczamy na ktore miejsce w tablicy powinna trafic tab[i]
            j++;
            
        for(int k=0;k<j;k++)
            top10[k] = top10[k+1];//przesuwamy

        if(j>=0)
            top10[j] = tab[i];//wstawiamy
        

    }

    int sum = 0;
    for(int i =0 ;i<10;i++)
        sum+=top10[i];

    cout << sum;
    

    return 0;
}