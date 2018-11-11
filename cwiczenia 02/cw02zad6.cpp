#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int tmpN =N;
    int maxBitMask = 1;
    while(tmpN>0)// liczymy maxBitMask = 2^k gdzie k to ilosc cyfr w N
    {
        maxBitMask*=2;
        tmpN/=10;
    }

    for(int bm = 1; bm<maxBitMask ; bm++)//kazdda bitmaska odpowiada dokladnie jednemu wykresleniu (bijekcja)
    {
        tmpN = N;
        int wykrLiczba = 0;// liczba tworzona przez wykreslenia
        int tmpBm = bm;
        int mnoznik = 1;//mnoznik kontrolujacy na gdzie wstawic kolejna cyfre

        while(tmpBm > 0)//przechodzimy po kolejnych cyfrach bm (bitmaski) w zapisie binarnym
        {
            if(tmpBm %2 == 1)
            {
                wykrLiczba += (tmpN%10)*mnoznik;
                mnoznik*=10;
            }
            tmpN/=10;
            tmpBm/=2;
        }

        if(wykrLiczba % 7 == 0)
            cout << wykrLiczba << endl;
    }

    return 0;
}
