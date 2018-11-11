#include <iostream>
#include <iomanip>

int main()
{
    int y;
    std::cin >> y;

    double prevX;
    double x = 1;

    double epsilon = 0.000001;

    do
    {
        prevX = x;
        x = x - (x*x*x - y)/(3*x*x);
    }while(prevX -x > epsilon || prevX -x < (-1)*epsilon);

    std::cout << std::setprecision(15) << x;


    return 0;
}
