#include <iostream>
#include <string>

using namespace std;

struct node
{
    int val;
    node* next;
};

// zadanie 6
void delete_add(node* &first, int key)
{
    node* temp = first;
    node* lag = NULL;
    while(temp!= NULL && temp->val != key)
    {
        lag = temp;
        temp = temp->next;
    }

    if(temp == NULL || temp->val != key) // no such element (or empty list)
    {
        node* p = new node;
        p->val = key;
        p->next = first;
        first = p;
    }else
    {
        lag->next = temp->next;
        delete temp;
    }
}

/* 7. Zbiór mnogościowy zawierający napisy jest reprezentowany w postaci
jednokierunkowej listy. Napisy w łańcuchu są uporządkowane
leksykograficznie. Proszę napisać stosowne definicje typów oraz funkcję
dodającą napis do zbioru. Do funkcji należy przekazać wskaźnik do listy
oraz wstawiany napis, funkcja powinna zwrócić wartość logiczną wskazującą,
czy w wyniku operacji moc zbioru uległa zmianie.*/

struct nodeS
{
    string napis;
    nodeS* next;
};

void init(nodeS* &first)
{
    //sentinel node
    nodeS* ps = new nodeS;
    ps->napis = "";
    ps->next = NULL;
    first = ps;
}

bool addToSet(nodeS* first , string nowyNapis)
{
    nodeS* first = first->next;
    nodeS* lag = first;

    while(first!=NULL && nowyNapis > first->napis)
    {
        lag = first;
        first = first->next;
    }

    if(first == NULL || nowyNapis != first->napis)
    {
        nodeS* p = new nodeS;
        p->napis = nowyNapis;
        p->next = first;
        lag->next = p;

        return true;
    }

    return false;
}

/* 8. Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej
elementów. */
void reverse(node* &first)
{
    node* temp = first;
    node* lag = NULL;
    first = NULL; // first - poczatek odwroconej listy

    while(temp!=NULL)
    {
        lag = temp;
        temp = temp->next;
        lag->next = first;
        first = lag;
    }
}

/* 9. Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy
element listy o wartościach typu int, usuwającą wszystkie elementy, których
wartość jest mniejsza od wartości bezpośrednio poprzedzających je
elementów. */
void deleteSome(node* first)
{
    //check if empty
    if(first == NULL)
        return;

    // first points to second element
    // lag points to first element
    node* lag = first;
    first = first->next;

    while(first!=NULL)
    {
        if(first->val < lag->val)
        {
            // delete
            lag->next = first->next;
            delete first;
            first = first->next;
        }else
        {
            //go forward
            lag = first;
            first = first->next;
        }
    }
}

int main()
{

    //
    return 0;
}