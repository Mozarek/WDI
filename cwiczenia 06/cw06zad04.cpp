#include <iostream>
#define N 10

using namespace std;


bool threeBlocks(int tab[N])//po prostu trzy wagi mają być tylko wewnatrz tej tablicy (zbyt proste)
{
    int tabWag[N];

    for(int i =0; i<N ;i++)
    {
        int temp = tab[i];
        tabWag[i]=0;
        for(int k=2;k*k < temp;k++)
        {
            if(temp%k == 0)
            {
                tabWag[i]++;
                while(temp%k==0)
                    temp/=k;
            }
        }
    }
}

int main()
{


    int tab[N] = {1,2,3,4,5,6,7,8,9,10};

    cout << (threeBlocks(tab) ? "YES" : "NO");

    return 0;
}