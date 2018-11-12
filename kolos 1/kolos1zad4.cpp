#include <iostream>
#define MAX 15

using namespace std;

int main()
{
    int tab[MAX] = {2,9,3,1,7,11,9,6,7,7,1,3,9,12,15};
    int top = 1;


    //wyjsciowo w zadaniu mamy miec trzycyfrowe losowe liczby ale uzywamy mniejszej tablicy
    //dla sprawdzenia poprawnosci algorytmu
    /*for(int i = 0; i<MAX;i++)
        tab[i] = rand()%900+100;*/

    for(int i=0 ; i<MAX ;i++)
    {
        for(int j=i+1 ; j<MAX ;j++)//podciag od i do j
        {
            //szukamy rewersu przeszukujac od poczatku cala tablice
            for(int k=0; k+j-i<MAX;k++)
            {
                //dla wybranego podciagu zliczamy ile elementow jest ulozonych odwrotnie
                int m;
                for(m=0; m < j-i+1  && tab[j-m] == tab[k+m]; m++);

                if(m== j-i+1)//jesli wszytkie elementy sa odwrotnie to jest to szukany rewers
                    if(j-i+1 > top)
                        top = j-i+1;
            }
        }
    }

    cout << top;

}