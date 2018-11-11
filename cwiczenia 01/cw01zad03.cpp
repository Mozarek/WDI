#include <iostream>
#include <cmath>


int main()
{
    int n;

    std::cout << "Podaj potencjalny iloczyn: ";
    std::cin >> n;

    int a = 0;
    int b = 1;

    do
    {
        b=b+a;
        a=b-a;
    }while(b<sqrt(n));

    if(a*b == n)
        std::cout << "Jest to iloczyn dwoch kolejnych liczb fibonacciego." << std::endl;
    else
        std::cout << "Niestety nie." << std::endl;

    return 0;
}
