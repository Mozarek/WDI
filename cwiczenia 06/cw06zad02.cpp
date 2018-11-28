#include <iostream>
#define MAX 5

using namespace std;

int t[MAX] = {1,15,17,100,3};

bool isPossible(int weight, int i)
{
    for(int p = i; p<MAX;p++)
    {
        //Zmiana wzgledem poprzedniego zadania:
        //
        //Dodajemy mozliwosc polozenia odwaznika do naszej masy ktora chcemy odwazyc na ta sama szalke wagi
        //Wowczas tj. zwiekszamy mase ktora chcemy odwazyc
        if(t[p]==weight || (t[p] < weight && isPossible(weight-t[p] , p+1)) || isPossible(weight+t[p] , p+1) )
            return true;
    }

    return false;
}

bool isPossibleToWeigh(int weight){ return isPossible(weight,0); }


int main()
{
    int myShot;

    cin >> myShot;
    while(myShot>0)
    {
        cout << (isPossibleToWeigh(myShot) ? "YES" : "NO") << endl;
        cin >> myShot;
    }

    return 0;
}