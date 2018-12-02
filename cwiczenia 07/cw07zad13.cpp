#include <iostream>

using namespace std;


void hanoi(int n, char from_rod , char to_rod , char aux)
{
    if(n==1)
    {
        cout << from_rod << "->" << to_rod << endl;
        return;
    }

    hanoi(n-1 , from_rod , aux , to_rod);
    hanoi(1 , from_rod , to_rod , aux);
    hanoi(n-1 , aux , to_rod , from_rod);

    return;
}

int main()
{
    hanoi(3 , 'A' , 'C' , 'B');
    return 0;
}