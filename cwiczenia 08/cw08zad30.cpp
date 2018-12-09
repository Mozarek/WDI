#include <iostream>

using namespace std;

int sumOfSth(int n)
{
    int primeDivisors[20];
    int max_j=0;

    for(int i =2; i<=n;i++)
    {
        if(n%i==0)
        {
            primeDivisors[max_j] = i;
            max_j++;

            while(n%i==0)
                n/=i;
        }
    }
    max_j--;

    



    int maxBitmask = (1 << max_j+1); // 2^max_j mozliwych

    int total = 0;
    int product , tempBM , j;
    for(int bitMask=1 ; bitMask < maxBitmask ; bitMask++)
    {
        product = 1;

        tempBM = bitMask;
        j=max_j;
        while(tempBM>0)
        {
            if(tempBM%2 == 1)
                product*= primeDivisors[j];

            j--;
            tempBM/=2;
        }
        cout << product << " j= " << j+1 << endl;

        total+= product;
    }

    return total;
}

int main()
{
    int number;
    cin >> number;

    cout << sumOfSth(number);

    return 0;
}