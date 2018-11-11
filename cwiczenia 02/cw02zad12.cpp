#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int a = N%10;
    int b;

    do
    {
        N = N/10;
        b = a;
        a = N%10;
    }while(N>0 && a<b);

    if(N==0)
        cout << "rosnacy";
    else
        cout << "nie jest rosnacy";




    return 0;
}
