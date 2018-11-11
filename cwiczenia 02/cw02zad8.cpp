#include <iostream>

int main()
{
    int a = 50;
    int b = 17;
    int n = 200;


    for(int i =0;i<n;i++)
    {
        std::cout << a/b;
        a = 10*(a%b);
    }

    return 0;
}
