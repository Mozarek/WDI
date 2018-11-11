#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;

    int cyfra = n%10;
    n/=10;

    while(n>0 && n%10 != cyfra)
    {
        n/=10;
    }

    if(n==0)
        cout << "unikalna";
    else
        cout << "nie jest unikalna";

    return 0;
}
