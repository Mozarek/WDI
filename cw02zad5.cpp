#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;

    int count5 = 0;
    int count2 = 0;

    long long lastNum = 1;
    int tempN;

    for(int i =2;i<=n;i++)
    {
        tempN = i;

        while(tempN%2 == 0)//wydzielamy przez dwojki
        {
            tempN/=2;
            count2++;
        }

        while(tempN%5 == 0)//wydzielamy przez piatki
        {
            tempN/=5;
            count5++;
        }

        lastNum=lastNum *(tempN%10)%10;
        //liczy sie tylko ostatnia cyfra
        //(wiemy ze nam sie nie wyzeruje, bo pozbylismy sie wszystkich dwojek i piatek)
    }

    count2 = (count2-count5)%4;

    switch(count2)
    {
    case 1:
        lastNum*=2;
        break;
    case 2:
        lastNum*=4;
        break;
    case 3:
        lastNum*=8;
        break;
    case 0:
        lastNum*=6;
    }

    cout << lastNum%10;

    return 0;
}
