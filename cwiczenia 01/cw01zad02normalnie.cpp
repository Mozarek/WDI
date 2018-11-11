#include <iostream>

int main()
{
    int rok = 2018;

    int a1 = 1;
    int a2 = 1;

    int x,y;

    int bestA1 = 1;
    int bestA2 = 2017;

    for(int a1 = 1 ; a1<= rok; a1++)
    {
        for(int a2 = a1; a2 <=rok; a2++)//sprawdzamy wszystkie możliwe pary z ktorych moglby wystartowac ciag a la fibonacci
        {
            x=a1;
            y=a2;
            while(y<rok)
            {
                y = y+x;
                x = y-x;
            }

            if(y==rok && (a1+a2)<(bestA1+bestA2))
            {
                bestA1 = a1;
                bestA2 = a2;
            }
        }
    }

    std::cout << bestA1 << " " << bestA2;
}
