#include <iostream>
#define N 4

using namespace std;

bool isPrime(int n)
{
    for(int i =2;i*i<=n;i++)
        if(n%i==0)
            return false;

    return true;
}

int znajdzSumy(int t1[N], int t2[N])
{
    int liczbaSum = 0;

    int mask[N];
    for(int i=0;i<N;i++)
        mask[i]=0;
    //zerowanie maski ktora dla i-tego elementu bedzie mowila:
    //mask[i]==1 to bierzemy i-ty el z t1
    //mask[i]==2 to bierzemy i-ty el z t2
    //mask[i]==0 to bierzemy i-te el z t1 i t2
    int bufor[2*N];
    int j;
    int sum;
    bool ostatniaMaska = false;

    do
    {
        j=0;
        sum=0;
        for(int i =0;i<N;i++)//liczymy sumę
        {
            if(mask[i]==0)
            {
                bufor[j]=t1[i];//w buforze przechowujemy wszystkie elementy sumy
                bufor[j+1] = t2[i];// bo przed wypisaniem musimy sprawdzic czy suma jest pierwsza
                j+=2;
                sum+=t1[i]+t2[i];
            }else if(mask[i]==1)
            {
                bufor[j] = t1[i];
                j++;
                sum+=t1[i];
            }else if(mask[i]==2)
            {
                bufor[j] = t2[i];
                j++;
                sum+=t2[i];
            }
        }

        if(isPrime(sum))//jesli jest pierwsza wypisujemy
        {
            liczbaSum++;
            
            cout << bufor[0];
            for(int i=1;i<j;i++)
                cout << " + " << bufor[i];
            
            cout << endl;
        }

        //tworzymy kolejna maske (dodajemy jeden do liczby trojkowej reprezentowanej przez mask[])
        int i = N-1;
        while(mask[i]==2)
            i--;

        if(i<0)
            ostatniaMaska = true;
        else
        {
            mask[i]++;
            
            for(i++;i<N;i++)
                mask[i]=0;
        }
        ////////////////////////
    }while(!ostatniaMaska);

    return liczbaSum;
}

int main()
{
    int t1[N] = {1,3,2,4};
    int t2[N] = {9,7,4,8};

    cout << znajdzSumy(t1, t2);

    return 0;
}