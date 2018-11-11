#include <iostream>

using namespace std;

int main()
{
    int a,b;

    cin >> a;
    cin >> b;

    bool tabA[10];
    bool tabB[10];

    for(int i =0;i<10;i++)
    {
        tabA[i] = false;
        tabB[i] = false;
    }

    while(a>0)
    {
        tabA[a%10-1] = true;
        a = a/10;
    }

    while(b>0)
    {
        tabB[b%10-1] = true;
        b = b/10;
    }

    int i;
    for(i =0;i<10;i++)
    {
        if(tabA[i] != tabB[i])
        {
            std::cout << "rozne";
            break;
        }
    }

    if(i==10)
        std::cout << "te same";
    return 0;
}
