#include <iostream>

#define N 200

bool isPrime(int n)
{
    if(n<2)
        return false;
    
    if(n==2)
        return true;

    if(n%2==0)
        return false;

    for(int i =3; i*i<n ; i+=2)
        if(n%i==0)
            return false;

    return true;
}

bool ustawSkoczki(int tab[N][N])
{
    for(int col =0;col<N-1;col++)
    {
        for(int row =0; row<N-1 ;row++)
        {
            if(row < N-2)
            {
                if(isPrime(tab[row][col] + tab[row+2][col+1]) ||
                   isPrime(tab[row][col+1] + tab[row+2][col]) )
                   return true;
            }

            if(col <N-2)
            {
                if(isPrime(tab[row][col] + tab[row+1][col+2]) ||
                   isPrime(tab[row+1][col] + tab[row][col+2]) )
                   return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}