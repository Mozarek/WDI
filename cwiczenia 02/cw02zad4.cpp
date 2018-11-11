#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;

    for(int i =1;i<=n;i = i*2)
    {
        for(int j =1;j<=n; j = j*3)
        {
            for(int k = 1;k<=n; k = k*5 )
            {
                if(k*i*j<=n)
                    cout << k*i*j << endl;
            }
        }
    }

    return 0;
}
