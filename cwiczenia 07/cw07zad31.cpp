#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10

using namespace std;

void eNki(int tab[] , int n , int suma , int i , int &count)
{
    if(suma == 0 && n == 0) // jesli znalezlismy konkretna sume zlozona z n elementów
        count++;

    if(i==N || n==0) // jesli juz mamy n elementow lub jesli skonczyla sie tablica
        return;

    eNki(tab , n-1 , suma - tab[i] , i+1 , count); // bierzemy element na i-tym miejscu
    eNki(tab , n , suma ,i+1 , count ); // nie bierzemy elementu na i-tym miejscu

    return;
}

int funkcja(int tab[] , int n , int suma) // funkcja obudowujaca rekurencje
{
    int count =0;
    eNki(tab , n , suma , 0 , count);

    return count;
}

int main()
{
    srand(time(NULL));

    int tab[N];

    for(int i =0;i<N ; i++)
    {
        tab[i] = rand()%10+1;
        cout << tab[i] << " ";
    }
    cout << endl;
        

    cout << funkcja(tab , 3 , 8);

    return 0;
}