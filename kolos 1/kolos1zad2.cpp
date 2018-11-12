#include <iostream>

using namespace std;

double abs(double x)
{
    return (x>0 ? x : (-1)*x);
}

int main()
{
    int k;
    cin >> k;

    double a2 = 1;
    double b2 = 2;
    double a1,b1;

    char ciag;
    char ciagn;

    //poczatkowa wartosc epsilon
    double Epsilon;
    if(abs(k-a2) <= abs(k-b2))
    {
        Epsilon = abs(k-a2);
        ciagn = 'a';

    }else
    {
        Epsilon = abs(k-b2);
        ciagn = 'b';
    }
    double newEpsilon;

    //poczatkowy indeks
    int numer =0;

    do
    {
        //przy kazdym wejsciu do petli
        ciag = ciagn;
        numer++;
        Epsilon = newEpsilon;

        //wyznaczamy nowe wyrazy wedlug wzoru
        a1 = a2;
        b1 = b2;

        b2 = a1+b1;
        a2 = a1 + b2/3.0;
        
        //tracking
        cout << "a" << numer+1 << ": " << a2 << "  ";
        cout << "b" << numer+1 << ": " << b2 << endl;

        //nowy epsilon to odleglosc k od a lub k od b
        if(abs(k-a2) <= abs(k-b2))
        {
            newEpsilon = abs(k-a2);
            ciagn = 'a';

        }else
        {
            newEpsilon = abs(k-b2);
            ciagn = 'b';
        }

    }while(newEpsilon < Epsilon);
    // dopoki nowy epsilon jest mniejszy niz poprzedni (bo wiemy ze ciagi a i b sa scisle rosnace)

    //podajemy odpowiedz: wyraz ktorego ciagu byl najblizej k
    cout << "numer: " << numer << endl;
    cout << "ciag: " << ciag << endl;

    return 0;
}