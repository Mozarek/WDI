#include <iostream>

using namespace std;

int main()
{
    int p,n;

    cin >> p;
    cin >> n;

    short int tab[33];

    int i=0;
    do
    {
        tab[i] = n%p;
        n = n/p;
        i++;
    }while(n>0);
    i--;

    do
    {
        switch(tab[i])
        {
        case 10:
            cout << "A";
            break;
        case 11:
            cout << "B";
            break;
        case 12:
            cout << "C";
            break;
        case 13:
            cout << "D";
            break;
        case 14:
            cout << "E";
            break;
        case 15:
            cout << "F";
            break;
        default:
            cout << tab[i];
        }
        i--;
    }while(i >=0);


    return 0;
}
