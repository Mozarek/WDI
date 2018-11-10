#include <iostream>
#include <iomanip>

int main()
{
    int a = 1;
    int b = 1;

    double prevFraction;
    double fraction = 1;

    double epsilon = 0.0000000000001;

    do
    {
        b = a+b;
        a = b-a;

        prevFraction = fraction;
        fraction = double(b)/a;
    }while(fraction -prevFraction > epsilon || fraction - prevFraction < (-1)*epsilon);// warunek konca |prevF - F| < Epsilon

    std::cout << std::setprecision(15) << fraction;

    return 0;
}
