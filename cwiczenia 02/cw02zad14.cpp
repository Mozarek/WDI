#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int liczbaCyfr = 0;
    int n = N;

    while(n >0)
    {
        n/=10;
        liczbaCyfr++;
    }

    n = N;

    while(n>0 && n%10 != liczbaCyfr)
    {
        n/=10;
    }

    if(n==0)
        cout << "nie";
    else
        cout << "tak";

    return 0;
}
