#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >>N;

    int dzielnik;

    for(int i = 1; i*i <= N;i++)
    {
        if(N%i == 0)
            dzielnik = i;
    }

    cout << dzielnik << ", " << N/dzielnik;



    return 0;
}
