#include <iostream>

const int MAX = 1000000;

int main()
{
    int a = 0;
    int b = 1;

    do
    {
        std::cout << b << std::endl;

        b=b+a;
        a=b-a;
    }while(b<MAX);

    return 0;
}
