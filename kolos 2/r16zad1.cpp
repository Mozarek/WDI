#include <iostream>

using namespace std;

int gcd(int a , int b)// algorytm euklidesa
{
    int c;
    while(b!=0)
    {
        c = a%b;
        a=b;
        b=c;
    }

    return a;
}

void podzial(int N ,int A , int B , int ia , int ib)
{
    if(N==0) // jak rozdzielilismy cala liczbe N miedzy A i B to konczymy
    {
        if(A>0 && B>0 && gcd(A,B) != 1)
            cout << A << " " << B << endl; 

        return;
    }

    // wywolujemy rekurencyjnie 'podzial' biorac ostatnia cyfre z N i umieszczajac ją na samym poczatku A lub B
    // aby zachowac wzgledna kolejnosc cyfr
    podzial(N/10 , (N%10)*ia + A , B , ia*10 , ib);
    podzial(N/10 , A , (N%10)*ib + B , ia , ib*10);

    return;
}

int main()
{
    int n;
    cin >> n;

    podzial(n ,0,0,1,1);

    return 0;
}