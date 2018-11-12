#include <iostream>
#define MAX 10

int main()
{
    int t[MAX];
    int dif = t[1]-t[0];
    int Len = 2;
    int MaxPlusLen = 0;
    int MaxMinusLen = 0;

    for(int i =2;i<MAX;i++)
    {
        if(t[i]-t[i-1] == dif)
            Len++;
        else
        {
            if(dif>0)
                MaxPlusLen = (Len>MaxMinusLen ? Len : MaxMinusLen);
            else if(dif<0)
                MaxMinusLen = (Len>MaxMinusLen ? Len : MaxMinusLen);

            dif = t[i] - t[i-1];
            Len = 2;
        }
    }

    if(dif>0)
        MaxPlusLen = (Len>MaxMinusLen ? Len : MaxMinusLen);
    else if(dif<0)
        MaxMinusLen = (Len>MaxMinusLen ? Len : MaxMinusLen);

    std::cout << MaxPlusLen - MaxMinusLen;

    return 0;
}