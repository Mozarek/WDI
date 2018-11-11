#include <iostream>

using namespace std;

int main()
{
    int tab[5];

    for(int i =0;i<5;i++)
        cin >> tab[i];

    if(tab[1] + tab[2] + tab[3] + tab[4] == 4*tab[0])
        cout << tab[0] << " ";

    if(tab[0] + tab[2] + tab[3] + tab[4] == 4*tab[1])
        cout << tab[1] << " ";

    if(tab[0] + tab[1] + tab[3] + tab[4] == 4*tab[2])
        cout << tab[2] << " ";

    int liczba;
    cin >> liczba;

    while(liczba != 0)
    {
        for(int j = 0; j<4;j++)
            tab[j] = tab[j+1];

        tab[4] = liczba;

        if(tab[0] + tab[1] + tab[3] + tab[4] == 4*tab[2])
            cout << tab[2] << " ";

        cin >> liczba;
    }

    if(tab[0] + tab[1] + tab[2] + tab[4] == 4*tab[3])
        cout << tab[3] << " ";

    if(tab[0] + tab[1] + tab[2] + tab[3] == 4*tab[4])
        cout << tab[4] << " ";

    return 0;
}
