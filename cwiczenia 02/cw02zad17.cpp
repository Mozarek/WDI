#include <iostream>

using namespace std;

long long pow(long long a, int n)
{
    long long res =1;

    for(int i = 0;i<n;i++)
        res*=a;

    return res;
}

int main()
{
    int n = 9;

    long long potegi[10];

    for (int i = 0;i < 10;i++)
        potegi[i] = pow(i,n);

    long long Amin = 1;

    for(int i =1;i<n;i++)
        Amin*=10;

    for(long long A = Amin; A < 10*Amin ; A++)
    {
        long long a = A;

        long long sum = 0;

        while(a>0 && sum < A)
        {
            sum += potegi[a%10];
            a/=10;
        }

        if(sum == A && a == 0)
            cout << A << endl;
    }
    return 0;
}
