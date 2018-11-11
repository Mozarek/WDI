#include <iostream>
#define MAX 10000


int main()
{
    int maxSteps = 0;
    int bestStartingVal;

    int a;
    int steps;
    for(int i =2;i<=MAX;i++)
    {
        steps = 0;
        a = i;

        while(a!=1)
        {
            a = (a%2)*(3*a+1)+(1-a%2)*a/2;
            steps++;
        }

        if(steps > maxSteps)
            bestStartingVal = i;
    }

    std::cout << bestStartingVal;

    return 0;
}
