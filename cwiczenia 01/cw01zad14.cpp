#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    while(a!=b)
    {
        if(a>b)
            b = a%b;
        else
            a = b%a;
    }

    while(b!=c)
    {
        if(b>c)
            c = b%c;
        else
            b = c%b;
    }

    std::cout << a;



    return 0;
}
