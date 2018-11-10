#include <iostream>

using namespace std;

void kombinacje(int A, int B)
{
    int a = A;
    int b = B;
    int lca = 0;
    int lcb = 0;

    while(a>0)
    {
        lca++;
        a/=10;
    }

    while(b>0)
    {
        lcb++;
        b/=10;
    }

    int tabBm[lca];

    for(int i = 0;i<lca;i++)
        tabBm[i] = i;

    while(true)
    {
        ///////////////////////////////////////////////////tworzymy liczbê wed³ug naszej bitmaski tabBm
        int genLiczba = 0;
        int jtabBm = lca-1;
        int mnoznik = 1;
        a=A;
        b=B;

        for(int i =lca+lcb-1 ; i>=0 ;i--)
        {
            if(tabBm[jtabBm]==i)
            {
                genLiczba+=mnoznik*(a%10);
                a/=10;
                jtabBm--;
            }
            else
            {
                genLiczba+=mnoznik*(b%10);
                b/=10;
            }
            mnoznik*=10;
        }
        /////////////////////////////////////////////////

        bool isPrime = true;
        for(int i =2;i*i<=genLiczba;i++)
            if(genLiczba%i ==0)
                isPrime = false;

        if(isPrime)
            cout << genLiczba << endl;


        //algorytm generowania kolejnej kombinacji
        if(tabBm[lca-1] < lca+lcb-1)
            tabBm[lca-1]++;
        else
        {
            int i = lca-2;
            while(i>=0 && tabBm[i] + 1 == tabBm[i+1])
                i--;

            if(i==-1)
                return;

            tabBm[i]++;
            for(int j = i+1;j<lca;j++)
                tabBm[j] = tabBm[j-1] + 1;
        }
    }
}


int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;

    kombinacje(a,b);

    return 0;
}
