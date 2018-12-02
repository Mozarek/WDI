#include <iostream>
#define MAX 5

using namespace std;

int t[MAX] = {1,2,3,4,5};

bool isPossible(int weight, int i, int depth)
{
    for(int j=0;j<depth;j++)
        cout << "\t";
    cout << "isPossible( " << weight << " , " << i << " )" << endl;
    
    if(i==MAX)
        return false;

    if(t[i]==weight || (t[i]<weight && isPossible(weight-t[i] , i+1, depth+1) ) || isPossible(weight , i+1, depth+1) )
        return true;

    return false;
}

bool isPossibleToWeigh(int weight){ return isPossible(weight,0,0); }


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