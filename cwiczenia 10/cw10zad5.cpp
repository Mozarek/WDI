/*5. Proszę napisać funkcję, która rozdziela elementy listy wejściowej do 10
list, według ostatniej cyfry pola val. W drugim kroku powstałe listy należy
połączyć w jedną listę, która jest posortowana niemalejąco według ostatniej
cyfry pola val.*/
#include <iostream>

struct node
{
    int val;
    node* next;
};

node* task(node* first)
{
    //rozdzielamy do 10 list wg ostatniej cyfry
    node* tabList[10];

    for(int i=0 ; i<10 ; i++)
        tabList[i] = NULL;

    node* lag = NULL;
    while(first!=NULL)
    {
        lag = first;
        first = first->next;

        //kazdy element z wyjsciowej listy przepinamy na poczatek jednej z dziesieciu nowopowstalych
        lag->next = tabList[ lag->val%10 ];
        tabList[ lag->val%10 ] = lag;
    }

    //laczymy 10 list w jedna tak aby byla posortowana wzgledem ostatniej cyfry
    node* total = NULL;

    first = NULL;
    lag = NULL;
    node* prevLast = NULL;

    for(int i=0;i<10;i++)
    {
        if(tabList[i]==NULL) //jesli dana lista jest pusta to ją pomijamy 
            continue;

        //jesli jest z czym to podpinamy poczatek obecnej listy do konca poprzedniej
        if(prevLast!=NULL)
            prevLast->next = tabList[i];
        else// jesli nie ma to jest to pierwszy fragment
            total = tabList[i];

        // przechodzimy na koniec obecnej listy
        first = tabList[i];
        lag = NULL;
        while(first!=NULL)
        {
            lag = first;
            first = first->next;
        }

        // ostatni element zapamietujemy 
        prevLast = lag;
    }

    return total;
}
