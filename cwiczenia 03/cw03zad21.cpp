#include <iostream>
using namespace std;

const int N = 10;

int maxOddPalindrome(int t[N])
{
    int maxLen = 0;

    bool isPal;

    for(int start = 0; start<N ; start++)
    {
        for(int end = start; end<N && t[end]%2 ==1 ; end++)
        {
            isPal = true;

            for(int i =0 ; i*2 < end-start ; i++)
                if(t[start+i] != t[end-i])
                    isPal = false;

            if(isPal)
                if(end-start+1 > maxLen)
                    maxLen = end-start+1;
        }
    }

    return maxLen;
}

int main()
{
    int tab[N] = {1,3,1,5,1,3,1,2,4,2};

    cout << maxOddPalindrome(tab);

    return 0;
}