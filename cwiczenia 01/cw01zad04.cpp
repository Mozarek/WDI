#include <iostream>


int main()
{
    int wantedSum;
    int currentSum = 0;

    std::cout << "podaj sume: ";
    std::cin >> wantedSum;



    int a = 0;
    int b = 1;

    do
    {
        currentSum+=b;
        b=b+a;
        a=b-a;
    }while(currentSum + b <wantedSum);

    if(currentSum + b == wantedSum)
        std::cout << "yea";
    else
    {
        currentSum+=b;

        a = 0;
        b = 1;

        do
        {
            currentSum-=b;
            b=b+a;
            a=b-a;
        }while(currentSum - b >wantedSum);
        if(currentSum-b == wantedSum)
        {
            std::cout << "yea";
        }else
            std::cout << "nope";
    }

    return 0;
}
