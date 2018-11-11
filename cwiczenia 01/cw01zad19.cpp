#include <iostream>
#include <iomanip>

int main()
{
    double result =1.0;
    double frac = 1.0;

    for(int i =1;frac > 0;i++)
    {
        frac = frac/i;
        result += frac;
    }

    std::cout << std::setprecision(10) << result;

    return 0;
}
