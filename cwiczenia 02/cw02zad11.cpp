#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int a =2;
    int wa;

    do
    {
        wa = a;
        while(wa<N)
        {
            wa+=a;
        }

        a = 3*a +1;
    }while(wa!=N && a < N);

    if(wa == N)
    {
        cout << "Tak";
    }else
    {
        cout << "nie";
    }



    return 0;
}
