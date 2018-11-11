#include <iostream>

int main()
{
    //tablica na ciag fibonacciego
    int tab[20];

    //poczatkowe wartosci ciagu
    int a = 0;
    int b = 1;

    //liczba ktora chcemy uzyskac w ciagu a la fibonacci
    int n = 2018;

    //generujemy ciag fibonacciego
    int i;
    for(i =0;a+b<=n;i++)
    {
        tab[i] = b;

        b=b+a;
        a=b-a;
    }
    i--;


    int bestA,bestB;
    bestB = n;
    for(int j = i;j>0;j--)//dla każdej pary kolejnych wyrazów ciągu fibonacciego
    {

        for(int k =1;n-tab[j]*k>0;k++)//szukamy parę liczb bestA i bestB które spelniaja: bestA*tab[j-1] + bestB*tab[j] = n
        {
            if((n-tab[j]*k)%tab[j-1]==0)
            {
                if(k < bestB && (n-tab[j]*k)/tab[j-1] < k)//jesli znajdziemy sprawdzamy czy sa lepsze od aktualnych najlepszych
                                                          //dodatkowo upewniamy sie ze bestA<bestB
                {
                    bestA = (n-tab[j]*k)/tab[j-1];
                    bestB = k;
                }
            }

        }
    }

    std::cout << "bestA: " << bestA << std::endl;
    std::cout << "bestB: " << bestB << std::endl;

    return 0;
}
