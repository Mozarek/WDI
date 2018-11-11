#include <iostream>
#define MAX 2700

using namespace std;

int main()
{
    int n;
    cin >>n;

    short result[MAX];
    result[0] = 1;
    short temp[MAX];
    int res_size = 1;

    int carry;
    int sum;

    for(int i =1;i<=n;i++)//przemnazamy przez kolejne liczby naturalne
    {

        for(int j = 0; j<res_size;j++)//przypisujemy temp = result
            temp[j] = result[j];

        for(int j=0 ; j<i-1 ; j++)//aby przemnozyc result przez i dodajemy temp do result (i-1) razy
        {
            carry = 0;
            for(int k=0;k<res_size;k++)//wykonujemy dodawanie dwoch liczb pisemnie gdzie k przebiga po kolejnych cyfrach
            {
                sum = result[k] + temp[k] + carry;
                carry = sum/10;
                result[k] = sum%10;
            }

            if(carry > 0)
            {
                result[res_size] = carry;
                res_size++;
            }
        }
    }

    for(int i = res_size-1;i>=0;i--)
    {
        cout << result[i];
    }

    cout << endl << endl;
    cout << res_size;


    return 0;
}
