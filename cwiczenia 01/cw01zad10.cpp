#include <iostream>
#include <cmath>

int main()
{
    double mianownik = 1;

    double poprzedni = 0;
    double eps = -0.000000001;

    while(poprzedni -1 < eps)
    {
        poprzedni = sqrt(0.5 + 0.5*poprzedni);
        mianownik*= poprzedni;
    }

    std::cout << 2.0/mianownik;

    return 0;
}
