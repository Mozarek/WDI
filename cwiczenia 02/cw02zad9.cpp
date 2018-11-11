#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >>N;

    int n = N;
    int sum;
    int a,b;

    do//sprawdzamy ka¿d¹ kolejn¹ liczbê wiêksza od N
    {
        n++;
        sum = 1;
        a = 0;
        b = 1;

        while(sum<n)
        {
            b=b+a;
            a=b-a;
            sum+=b;
        }

        a=0;
        b=1;

        while(sum>n)
        {
            sum-=b;
            b=b+a;
            a=b-a;
        }

    }while(sum==n);//az trafimy na taka ktorej nie udalo sie przedstawic jako sumy

    cout << n;

    return 0;
}
