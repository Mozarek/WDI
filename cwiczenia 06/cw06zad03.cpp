#include <iostream>
#define MAX 5

using namespace std;

int t[MAX] = {1,15,17,100,3};

bool isPossible(int weight, int i)
{
    //warunek konca
    if(weight == 0)
        return true;

    for(int p = i; p<MAX;p++)
    {
        //jesli damy odwaznik na szalke przeciwna
        if(isPossible(weight-t[p] , p+1) )
        {
            cout << t[p] << " ";
            return true;
        }
        
        //jesli damy odwaznik na szalke z naszą masą
        if(isPossible(weight+t[p] , p+1) )
        {
            cout << "-" << t[p] << " ";
            return true;
        }
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