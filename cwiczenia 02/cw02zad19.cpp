#include <iostream>
#define MAX 10

using namespace std;

int main()
{

    for(int n = 1 ; n<MAX;n++)
    {
        for(int m = n+1;m<MAX;m++)
        {
            cout << m*m - n*n << " ";
            cout << 2*m*n << " ";
            cout << m*m + n*n << endl;
        }
    }

    return 0;
}
