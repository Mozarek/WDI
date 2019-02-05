#include <iostream>

using namespace std;

/*
2. Zastosowania listy do implementacji tablicy rzadkiej. Proszę napisać
trzy funkcje:
- void init(node *&tab) – inicjalizującą tablicę,
- int value(node *tab, int n) – zwracającą wartość elementu o indeksie n,
- void set(node *&tab, int n, int value) – postawiającą wartość value pod
indeks n.
*/

struct node
{
    int value;
    int index;
    node* next;
};

// inititalize the tab - make the dummy node
void init(node* &tab)
{
    // adding sentinel
    node* s = new node;
    s->value = 0;
    s->index = -1;
    s->next = NULL;

    tab = s;
}

// get the value of tab[n]
int value(node* tab , int n)
{
    tab = tab->next; // first element is always here (dummy node)

    while(tab!= NULL && tab->index < n)
        tab = tab->next;

    if(tab!=NULL && tab->index == n)
        return tab->value;

    return 0;

}

// set the value of tab[n] to val
void set(node* tab , int n , int val)
{
    node* lag = tab;
    tab = tab->next;

    while(tab!=NULL && tab->index < n)
    {
        lag = tab;
        tab= tab->next;
    }

    if(tab!=NULL && tab->index == n)
    { // node with index 'n' exists
        tab->value = val;
    }else // no node with such index
    {
        node* p = new node;
        lag->next = p;
        p->index = n;
        p->value = val;
        p->next = tab;
    }
}

int main()
{
    //
    return 0;
}