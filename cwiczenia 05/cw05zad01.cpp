#include <iostream>

int abs(int a){return (a>0 ? a : (-1)*a);}

int gcd(int a, int b)
{
    int temp;

    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }


    while(a>b)
    {
        temp = a%b;
        a = b;
        b = temp;
    }

    return a;
}

struct ulamek
{
    int l=1;
    int m=1;//dodatnia wieksza od zera
};

ulamek dodaj(ulamek a , ulamek b)
{
    ulamek wynik;

    wynik.m = a.m*b.m;
    wynik.l = a.l*b.m + b.l*a.m;

    skroc(wynik);

    return wynik;
}

void skroc(ulamek &a)
{
    int d = gcd(abs(a.l), a.m);

    a.l/=d;
    a.m/=d;
}

int main()
{
    return 0;    
}