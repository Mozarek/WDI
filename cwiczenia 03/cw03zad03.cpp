#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool tab[n];

    for(int i =1;i<n;i++)//ustawiamy wszystkie liczby jako pierwsze
        tab[i] = true;

    int j;
    for(int i =2; i*i<=n;i++)
    {
        if(tab[i-1] == true)
        {
            j = i+i;
            while(j<=n)
            {
                tab[j-1] = false;//jeśli jest czegoś wielokrotnością to jest złożona
                j+=i;
            }
        }
    }

    for(int i=1 ; i<n ; i++)
    {
        if(tab[i] == true)
            cout << i+1 << " ";
    }

    return 0;
}
