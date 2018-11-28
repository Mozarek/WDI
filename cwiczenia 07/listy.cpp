#include <iostream>

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

void insert_last(node* &first , int n)//wstawianie na koncu listy
{
    node* p = new node;
    p->w = n;
    p->next = NULL;

    if(first == NULL)
        p = first;
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
        if(tmp->next == NULL);
            //usun jedyny element
        else
        {
            while(tmp->next->next != NULL)
                tmp = tmp->next;
        }    
    }
    
}

void insert(node* &first, int n)
{
    node *kolejny = first;
    node *poprzedni = NULL;

    while(kolejny!= NULL && kolejny-> w < n)
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

    }//2 przypadek - najmniejszy eleement - (kolejny == first && poprzedni == NULL
    else if(poprzedni == NULL && kolejny == first)
    {
        tmp->next = kolejny;
        first = tmp;
    }//3 przypadek - środek - (kolejny wskazuje na element po wstawieniu && poprzedni wskazuje na element przed wstawieniem)
    else if(poprzedni != NULL)
    {
        poprzedni->next = tmp;
        tmp->next = kolejny;
    }
    //4 przypadek - koniec - (kolejny == NULL && poprzedni wskazuje na ostatni element)
    //MERGE Z 3 PRZYPADKIEM
}

int main()
{

    node* first;

    //dołączamy na początku element
    node* p = new node;
    p->w = 6; // wstawiamy wartosc
    p->next = first;
    first = p;


    //dołączamy na końcu
    node* p1 = new node;
    p1->w = 7;
    p1->next = NULL;

    node* r = first;
    if(first!= NULL)// przypadek dla pustej
    {
        while(r->next != NULL)// dojezdamy pomocniczym wskaznikiem do ostatniego elementu
        r = r->next;
    }

    r->next = p1;
}

//TO DO:

//usuwanie elementu o zadanym kluczu
//wstawianie - wersja z wartownikiem