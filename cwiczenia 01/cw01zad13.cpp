#include <iostream>
#define MAX 1000000

int main()
{
    int a,b;
    int sumA, sumB;
    for(a = 1;a<MAX;a++)// dla każdej liczby z przedziału
    {
        sumA = 1;

        for(int i =2;i*i<a;i++)// liczymy sumę dzielników właściwych dla tej liczby
        {
            if(a%i == 0)
                sumA+= i + a/i;
        }
        if(sumA > a)// jesli suma (liczba B) jest wieksza od tej liczby (A)
        {
            b = sumA;
            sumB = 1;
            for(int j = 2;j*j<b && sumB <= a;j++)//sprawdamy czy suma dzielników właściwych liczby B jesg równa liczbie A
            {
                if(b%j == 0)
                    sumB+=j + b/j;
            }

            if(a == sumB)
                std::cout << a << " " << b << std::endl;
        }


    }
    return 0;
}
