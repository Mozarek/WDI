#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double X = 10;
    double prevX;
    double epsilon = 0.00001;

    do
    {
        prevX = X;

        X = X - (pow(X,X)-2017.0)/(pow(X,X)*(log(X)+1));


    }while(prevX - X > epsilon || prevX - X < (-1)*epsilon);

    cout << X << endl;

    return 0;
}
