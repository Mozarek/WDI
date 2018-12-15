#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
};

/* zadanie 1 */
void insertLast(node* &first, int val)
{
    node* p = new node;
    p->value = val;
    p->next = NULL;

    if(first==NULL) // empty list
    {
        first = p;
    }else // nonempty list
    {
        node* temp = first;

        while(temp->next !=NULL)
            temp = temp->next;

        temp->next = p;
    }
}

/*zadanie 2*/
void deleteLast(node* &first)
{
    if(first==NULL) // empty
        return;
    else if(first->next==NULL) // one element
    {
        delete first;
        first = NULL;
    }
    else // at least two elements
    {
        node* temp = first->next;
        node * lag = first;

        while(temp->next != NULL)
        {
            lag = temp;
            temp = temp->next;
        }

        delete temp;
        lag->next = NULL;
    }
}

/*zadanie 3*/
void deleteEveryTwo(node* first)
{
    node* lag = NULL;

    while(first!=NULL && first->next!=NULL)
    {
        lag = first;
        first = first->next;

        lag->next = first->next;
        delete first;
        first = lag->next;
    }
}

/*zadanie 4*/
bool carry(node* p)
{
    if( p->next==NULL || carry(p->next) )
    {
        if(p->value<9)
        {
            p->value++;
            return false;
        }
        else
        {
            p->value = 0;
            return true;
        }
    }
    return false;;
}

void incrementNum(node* &first)
{
    if(carry(first))
    {
        node* p = new node;
        p->value = 1;
        p->next = first;
        first = p;
    }
}


/*zadanie 5*/
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

int carry2(node* a , node* b , node* &c)
{
    if( a==NULL || b == NULL)
    {
        return 0;
    }else
    {
        int carry = carry2(a->next , b->next , c) + a->value + b->value;

        node* p = new node;
        p->next = c;
        p->value = carry%10;
        c = p;

        return carry/10;
    }
}


node* addNums(node* firstA , node* firstB)
{
    int digitDiff = len(firstA) - len(firstB);

    if(digitDiff < 0)
    {
        node* temp;
        temp = firstA;
        firstA = firstB;
        firstB = temp;

        digitDiff *= -1;
    }
    // teraz lenA >= lenB
    
    node* p = NULL;
    for(int i =0; i<digitDiff ;i++)
    {
        p  = new node;
        p->value = 0;
        p->next = firstB;
        firstB = p;
    }

    node* firstC = NULL;
    int carry = carry2(firstA , firstB , firstC);
    if(carry >0)
    {
        p = new node;
        p->value = carry;
        p->next = firstC;
        firstC = p;
    }

    return firstC;
}

void deleteAll(node* first)
{
    node* lag = NULL;

    while(first!=NULL)
    {
        lag = first;
        first = first->next;

        delete lag;
    }
}

int main()
{
    node *a = NULL;
    node* b = NULL;
    node *c = NULL;

    for(int i=0;i<10 ;i++)
    {
        insertLast(a , (i*7+6)%10);
        insertLast(b , (i*7+6)%10);
        cout << (i*7+6)%10 << " ";
    }
    cout << endl;
    c = addNums(a , b);
    
    node* temp = c;
    while(temp!=NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    
    deleteAll(a);
    deleteAll(b);
    deleteAll(c);
    //
    return 0;
}