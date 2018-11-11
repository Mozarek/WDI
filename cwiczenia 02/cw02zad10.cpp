#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >>k;

    double Pole = 0;
    double Epsilon = 0.0001;

    for(double x=1;x<k;x+=Epsilon)
    {
        Pole+= (1.0/x)*Epsilon;
    }

    cout << Pole;

    return 0;
}
