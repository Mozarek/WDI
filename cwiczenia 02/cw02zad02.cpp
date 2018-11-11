#include <iostream>

int main()
{
    int podana;
    bool ans = false;
    std::cin >> podana;

    int n=1;
    int wartosc = n*n + n + 1;
    int wielokrot = wartosc;

    for(int n=1; wartosc <= podana; n++)
    {
        while(wielokrot < podana)
            wielokrot+=wartosc;

        if(wielokrot == podana)
        {
                ans = true;
                break;
        }
        wartosc += 2*n;
        wielokrot = wartosc;
    }

    if(ans)
        std::cout << "super";
    else
        std::cout << "nie";
    return 0;
}
