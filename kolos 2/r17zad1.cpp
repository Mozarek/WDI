#include <iostream>

#define N 8

int licz(int tab[N][N] ,int x1, int x2 ,int y1 ,int y2)
{
    int sum =0;
    if(x1==x2)
    {
        for(int i =0;i<N;i++)
        { 
            sum+= tab[i][x1]; //suma pojedynczej kolumny
            if(x1!=i)
                sum+= tab[y1][i] + tab[y2][i]; // suma dwoch wierszy bez miejsc wiez
        }
            
    } else if(y1==y2)
    {
        for(int i =0;i<N;i++)
        { 
            sum+= tab[y1][i]; //suma pojedynczego wiersza
            if(y1!=i)
                sum+= tab[i][x1] + tab[i][x2]; //suma dwoch kolumn bez miejsc wiez
        }
            
    } else
    {
        for(int i=0; i<N; i++) // suma dwoch wierszy i dwoch kolumn
        {
            sum+= tab[i][x1] + tab[i][x2] + tab[y1][i] + tab[y2][i];
        }
        sum-= 2*tab[y1][x1] + 2*tab[y2][x2]; // policzylismy dwa razy obie wieze a nie powinnismy w ogole liczyc
    }

    return sum;
}

bool dwieWieze( int tab[N][N] , int x1, int x2 , int y1, int y2)
{
    int tabW[N] , tabK[N];

    int currentSum= licz(tab ,x1,x2,y1,y2);

    for(int i=0;i<N;i++)
    {
        if( x1 != i && licz(tab , i ,x2,y1,y2) > currentSum)
            return true;
        if( x2 != i && licz(tab ,x1, i ,y1,y2) > currentSum)
            return true;
        if( y1 != i && licz(tab ,x1,x2, i ,y2) > currentSum)
            return true;
        if( y2 != i && licz(tab ,x1,x2,y1, i ) > currentSum)
            return true;
    }

    return true;
}

int main()
{

    //coś

    return true;
}