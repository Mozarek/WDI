#include <iostream>
#define MAX 5
using namespace std;

void maxSurroundingSum(int tab[MAX][MAX] , int &x , int &y)// output przez referencje
{
    int directions[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};//y,x

    int maxSum = 0;
    int sum;

    for(int row=0 ; row<MAX ; row++)
    {
        for(int col=0; col<MAX ; col++)//dla kazdego elementu liczymy sume sasiadujacych z nim pol
        {
            sum = 0;

            for(int i =0;i<8;i++)//sumujemy wszystkich sasiadow uzywajac directions[][]
            {
                if(row + directions[i][0] >= 0 && row + directions[i][0] < MAX &&
                   col + directions[i][1] >= 0 && col + directions[i][1] < MAX)//jesli sasiad istnieje
                   sum+= tab[row + directions[i][0]][col + directions[i][1]];
            }

            if(sum > maxSum)// jesli policzona suma jest wieksza od dotychczasowej maksymalnej
            {
                maxSum = sum;
                y = row+1;//formatujemy zeby rzad i kolumna byly numerowane od 1 (zamiast od zera)
                x = col+1;
            }
                

        }
    }
}


int main()
{
    int x;
    int y;
    int tab[MAX][MAX] = {{64,45,23,27,78},
                         {21,54,78,53,48},
                         {64,68,47,28,32},
                         {94,55,33,22,77},
                         {89,33,22,35,70}};

    maxSurroundingSum(tab , x , y);

    cout << "Rzad: " << y << endl;
    cout << "Kolumna: " << x << endl;


    return 0;
}