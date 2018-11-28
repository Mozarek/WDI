#include <iostream>

struct hetman {
 int w; // wiersz 0..99
 int k; // kolumna 0..99
};

struct dane {
 hetman t[100]; // położenie hetmanów
 int N; // liczba hetmanów
};

bool noChecking(dane dataSet)
{
    for(int i =0; i<dataSet.N ;i++)
    {
        for(int j=i+1; j<dataSet.N ;j++)//sprawdzamy pare kazdych dwoch kroli
        {
            if(dataSet.t[i].k == dataSet.t[j].k)//jezeli leza w jednej kolumnie
                return false;

            if(dataSet.t[i].w == dataSet.t[j].w)//jezeli leza w jednym wierszu
                return false;

            if(dataSet.t[i].k + dataSet.t[i].w  == dataSet.t[j].k + dataSet.t[j].w)//jezeli leza na skosie prawo-gora
                return false;

            if(dataSet.t[i].k - dataSet.t[i].w  == dataSet.t[j].k - dataSet.t[j].w)//jezeli leza na skosie prawo-dol
                return false;
        }
    }

    return true;    
}