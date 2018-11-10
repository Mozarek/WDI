#include <iostream>
#define MAX 2000


using namespace std;

int main()
{
    int a,b;
    cin >> a;
    cin >> b;

    cout << a/b << ".";

    a = (a%b)*10;

    int tabDec[MAX];
    int tabRem[MAX];

    bool repeated = false;
    int i =0;
    do
    {
        tabDec[i] = a/b;
        tabRem[i] = a%b;
        a = (a%b)*10;

        for(int j =0;j<i;j++)
        {
            if(tabRem[j] == tabRem[i])
            {
                //wypisz
                for(int k=0;k<i;k++)
                {
                    if(k==j)
                        cout << "(";
                    cout << tabDec[k];
                }
                cout << ")";

                //zaznacz ze znalezlismy rozwiniecie dziesietne
                repeated = true;
            }
        }
        i++;
    }while(tabRem[i-1] != 0 && !repeated);

    if(!repeated)
    {
        for(int k =0;k<i;k++)
            cout<< tabDec[k];
    }

    return 0;
}
