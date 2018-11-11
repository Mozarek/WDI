#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double A,B, prevA,prevB;
    cin >> A;
    cin >> B;

    double epsilon = 0.00000000001;

    while(A-B > epsilon || A-B < (-1)*epsilon)
    {
        prevA = A;
        prevB = B;

        A = sqrt(prevA*prevB);
        B = (prevA + prevB)/2.0;
    }

    cout << setprecision(12) << B;

    return 0;
}
