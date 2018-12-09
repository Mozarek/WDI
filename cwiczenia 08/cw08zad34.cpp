#include <iostream>

using namespace std;

int sumOfSth(int n)
{
    int primeDivisors[20];
    int max_j=0;

    // getting all the prime divisors of n and storing them in "primeDivisors" array
    // also counting the number of divisors with max_j
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



    // every subset of "PrimeDivisors" set is represented by bitMask of length max_j 
    // 1 - the element is a member of the subset
    // 0 - the element is not a member of the subset

    int maxBitmask = (1 << max_j); // there are 2^max_j possible subsets 

    int total = 0;
    int product , tempBM , j;
    for(int bitMask=1 ; bitMask < maxBitmask ; bitMask++)
    {
        tempBM = bitMask; // to destroy "tempBM" while getting binary representation

        // for each subset we calculate the product and add it to the total
        product = 1;
        j=max_j;
        while(tempBM>0)
        {
            if(tempBM%2 == 1)
                product*= primeDivisors[j];

            j--;
            tempBM/=2;
        }

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