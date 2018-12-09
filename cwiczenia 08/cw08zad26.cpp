#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

bool generateNextCombination(bool tab[] , int size)
{
    // we are generating next combination which represents the largest binary number smaller than the one 
    // represented by current combination
    int i = size-1;
    int j = 0;

    while(tab[i] == 1) {i--; j++;}

    while(tab[i] == 0) {i--;}

    if(i==0)
        return false;

    tab[i] =0;
    tab[i+1]=1;
    i+=2;

    int k;
    for(k=0 ; k<j ; k++)
        tab[i+k] = 1;
    
    for(i=i+k ; i<size ; i++)
        tab[i] = 0;

    return true;
}


bool isComplex(bool num[] , int size)
{
    if(size<3)
        return false; //size <3  <=> num < 4

    if(num[size-1] == 0) // even numbers are complex
        return true;

    // converting our array to "long long" type
    long long number = 0;
    for(int i =0; i<size ;i++)
        number = 2*number + num[i];

    
    // looking for factors
    for(long long p=3; p*p <= number; p+=2)
        if(number%p==0)
            return true;

    return false;
}



int main()
{
    int A, B;
    cin >> A >> B;

    int N = A+B;

    if(N > 63)// then it might not fit into long long in the "isComplex" function
    {
            cout << "error";
            return 0;
    }

    //dynamic array since we got the size from the user
    bool * binNum = new bool [N];

    //make the largest possible number out of A 1's and B 0's
    for(int i =0;i<A;i++)
        binNum[i] = 1;

    for(int i =A;i<N;i++)
        binNum[i] = 0;
    //

    //measure the time
    clock_t t;
    t = clock();

    //the main part of the algorithm
    int count =0;
    do
    {
        if(isComplex(binNum , N))
            count++;
    }while(generateNextCombination(binNum , N));

    //display measured time
    t = clock() - t;
    cout << "Time elapsed: " << float(t)/ CLOCKS_PER_SEC << endl;
    
    //the proper answer to the task
    cout << "The result is: " << count << endl;


    return 0;
}