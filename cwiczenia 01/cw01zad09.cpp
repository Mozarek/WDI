#include <iostream>

int main()
{
    double x;
    std::cin >> x;

    double value = 1;
    double square = x*x;
    double i = 1;
    double previousValue;
    double epsilon = 0.000001;
    double skladnik = 1;

    do
    {
        previousValue = value;
        skladnik*= (-1)*square;
        skladnik/= i*(i+1);
        i+=2;
        value+= skladnik;
    }while((value - previousValue >= epsilon) || ((value - previousValue) <= (-1)*epsilon)); // |val - lastVal| >= epsilon

    std::cout << value;

    return 0;
}
