#include <iostream>

using namespace std;

int func(int n)
{
    if(n<2)
        return n;

    return abs(n%2 - func(n/2));
}

int main()
{

    int test[20];
    for(int i =0;i<20;i++)
    {
        test[i] = rand()%100+1;
        cout << "f( " << test[i] << " )= " << func(test[i]) << std::endl;
    }
}