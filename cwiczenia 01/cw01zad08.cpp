#include <iostream>
#include <cmath>

int main()
{
    double Y = 2017;

    double X;
    double eps = 0.001;
    double val;
    double p = 0;
    double q = Y;

    do
    {
        X = (p+q)/2;
        val = pow(X,pow(X,X));

        if (val > Y)
            q = (p+q)/2;
        else if(val< Y)
            p = (p+q)/2;
        else
            break;

        std::cout << val <<std::endl;
    }while((val - Y) > eps || (val - Y) < (-1)*eps);


    std::cout << X;
    return 0;
}
