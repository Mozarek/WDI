#include <iostream>
#include <string>

using namespace std;

void podzial(int n, int p, string wynik)
{
    if(n==0)
        cout << wynik << endl;
    else
    {
        for(int i=p; i<=n ; i++)
        {
            podzial(n-i , i ,wynik + " " + to_string(i));
        }
    }
}

int main()
{
    podzial(4, 1 , "");
    return 0;
}