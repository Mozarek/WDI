#include <iostream>

using namespace std;

struct node
{
        int w;
        node* next;   
};

struct twoWayNode
{
    int w;
    twoWayNode* next;
    twoWayNode* prev;
};


void insert_by_value_sentinel(node* first , int n)
{
    node* kolejny = first->next; //first wskazuje na sentinela
    node* poprzedni = first;

    while(kolejny != NULL && kolejny->w < n)//sprawdzamy wartosc dopiero elementu po sentinelu
    {
        poprzedni = kolejny;
        kolejny = kolejny->next;
    }

    node* p = new node;
    p->w = n;
    p->next = kolejny;
    poprzedni->next = p;
}

void insert_last(node* &first , int n)//wstawianie na koncu listy
{
    cout << "wstawiam" << endl;

    node* p = new node;
    p->w = n;
    p->next = NULL;

    if(first == NULL)
        first = p;
    else
    {
        node* r = first;

        while(r->next != NULL)// dojezdamy pomocniczym wskaznikiem do ostatniego elementu
            r = r->next;
        
        r->next = p;
    }
}

int len(node* first)//obliczanie dlugosci listy
{
    int length = 0;
    while(first!=NULL)
    {
        first = first->next;
        length++;
    }

    return length;
}

void delete_last(node* &first)
{
    node* tmp = first;
    if(tmp!=NULL)
    {
        if(tmp->next == NULL)//usun jedyny element
        {
            delete tmp;
            first = NULL;
        }
        else
        {
            while(tmp->next->next != NULL)
                tmp = tmp->next;

            delete tmp->next;
            tmp = NULL;
        }    
    }
    
}

void insert(node* &first, int n)
{
    node *kolejny = first;
    node *poprzedni = NULL;

    while(kolejny!= NULL && kolejny->w < n)
    {
        poprzedni = kolejny;
        kolejny = kolejny->next;
    }

    //tworzymy nowy element ktory wstawiamy
    node* tmp = new node;
    tmp->w = n;
    tmp->next = NULL;

    //1 przypadek - pusta lista - (kolejny == NULL && poprzedni == NULL)
    if(poprzedni == NULL && kolejny == NULL)
    {
        first = tmp;

    }//2 przypadek - najmniejszy eleement - (kolejny == first && poprzedni == NULL)
    else if(poprzedni == NULL && kolejny == first)
    {
        tmp->next = kolejny;
        first = tmp;
    }//3 przypadek - środek - (kolejny wskazuje na element po wstawieniu && poprzedni wskazuje na element przed wstawieniem)
    else
    {
        poprzedni->next = tmp;
        tmp->next = kolejny;
    }
    //4 przypadek - koniec - (kolejny == NULL && poprzedni wskazuje na ostatni element)
    //MERGE Z 3 PRZYPADKIEM
}

void delete_with_key(node* &first , int n)
{
    node* kolejny = first;
    node* poprzedni = NULL;

    while(kolejny!=NULL && kolejny->w !=n)
    {
        poprzedni = kolejny;
        kolejny = kolejny->next;
    }

    if(poprzedni == NULL && kolejny != NULL)
    {
        delete first;
        first = NULL;
    }else if(kolejny != NULL)
    {
        poprzedni->next = kolejny->next;
        delete kolejny;
    }
}

void write_sentinel(node* first)
{
    first = first->next; //przeskakujemy sentinela

    cout << "wypisuje: ";

    while(first!=NULL)
    {
        cout << first->w << " ";
        first = first->next;
    }

    cout << endl;
}

int main()
{

    node* first = NULL;

    insert_last(first, -2); //sentinel

    for(int i =0;i<5;i++)
        insert_last(first, i*3);
    //

    insert_by_value_sentinel(first, 13);

    write_sentinel(first);
}

//TO DO:

//usuwanie elementu o zadanym kluczu #DONE
//wstawianie - wersja z wartownikiem #DONE