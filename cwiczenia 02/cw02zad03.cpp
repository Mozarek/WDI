#include <iostream>

int main()
{

    int num;
    std::cin >> num;

    int best;

    for(int i =1;i *i <=num; i++ )
    {
        if(num%i == 0)
            best = i;
    }

    std::cout << best << " " << num/best;
    return 0;
}
