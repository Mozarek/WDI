#include <iostream>
#define MAX 1000000

int main()
{
    int currentSum;
    int j;
    for(int n = 1; n<MAX;n++)
    {
        currentSum = 1;
        j =2;
        for(j =2;j*j < n && currentSum <= n;j++)
        {
            if(n%j == 0)
            {
                currentSum+=j + n/j;
            }
        }
        if(j*j == n)
            currentSum+=j;
        if(currentSum==n)
            std::cout << n << std::endl;

    }
    return 0;
}
