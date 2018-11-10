#include <iostream>
#define MAX  1000

using namespace std;

int main()
{

    for (int A =2 ; A<MAX ; A++)
    {
        int sumOfDigits = 0;
        int a =A;

        while(a>0)
        {
            sumOfDigits+=a%10;
            a/=10;
        }

        a=A;
        int tempi;
        int FactorsSumOfDigits = 0;
        int i;
        for(i = 2;i<=a;i++)
        {
            while(a%i == 0)
            {
                a/=i;
                tempi = i;
                while(tempi>0)
                {
                    FactorsSumOfDigits+=tempi%10;
                    tempi/=10;
                }

            }
        }

        if(sumOfDigits == FactorsSumOfDigits && i-1!=A)
            cout << A << endl;
    }

    return 0;
}
