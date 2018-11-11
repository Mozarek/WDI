#include <iostream>

int main()
{
    int a1 = 0;
    int b1 = 1;

    int a2;
    int b2;

    int iloczyn_szukany;

    bool czy = false;

    std::cin >> iloczyn_szukany;

    while(b1 < iloczyn_szukany || b1==1)
    {
        a2 = b1;
        b2 = b1+a1;
        while(b1*b2 < iloczyn_szukany)
        {
            b2= b2+a2;
            a2= b2-a2;

        }

        if(b1*b2 == iloczyn_szukany)
        {
            std::cout << b1 << " " << b2 << std::endl;
            czy = true;
            break;
        }


        b1+= a1;
        a1 = b1 - a1;
    }

    if(czy == true)
        std::cout << "tak";
    else
        std::cout << "nie";

    return 0;
}
