#include <iostream>

using namespace std;

int main()
{
    int a0 = 0;
    int a1 = 1;
    int a2;

    int b = 2;
    int b1;

    int wczytLiczba;
    cin >> wczytLiczba;

    if(wczytLiczba == a0)
    {
        cout << "   " << b << endl;

        cin>>wczytLiczba;
        if(wczytLiczba == a1)
        {
            do
            {
                b = b + 2*a0;
                cout << "   " << b << endl;

                a2 = a1 - b*a0;
                a0 = a1;
                a1 = a2;

                cin >> wczytLiczba;
            }while(wczytLiczba == a1);
        }
    }

    return 0;
}
