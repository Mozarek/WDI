#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;

    //liczymy nww(a,b)
    int nww = a*b;

    int temp;
    while(b!=0)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    nww = nww/a; //ze wzoru nww(a,b) = (a*b)/nwd(a,b)


    //liczymy nww(nww(a,b),c)
    int ResNww = nww*c;

    while(c!=0)
    {
        temp = nww%c;
        nww = c;
        c = temp;
    }
    ResNww = ResNww/nww;

    std::cout << ResNww;

    return 0;
}
