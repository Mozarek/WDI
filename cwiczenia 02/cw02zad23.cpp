#include <iostream>

using namespace std;

int main()
{
    bool odp;

    int a;
    int b;

    bool tabCyfrA[16];

    cin>>a;
    cin>>b;

    int tempA;
    int tempB;

    int p;
    for(p=2;p<=16 && !odp ; p++)
    {
        for(int i =0;i<16;i++)
            tabCyfrA[i] = false;

        tempA = a;
        tempB = b;

        odp = true;

        while(tempA>0)
        {
            tabCyfrA[tempA%p] = true;
            tempA/=p;
        }

        while(tempB>0 && odp)
        {
            if(tabCyfrA[tempB%p] == true)
                odp = false;

            tempB/=p;
        }
    }

    if(odp)
        cout << p-1;
    else
        cout << "nie ma takiej podstawy";


    return 0;
}