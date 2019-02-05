#include <iostream>

struct node
{
    int val;
    node* next;
};

void unique_only(node* &first)
{
    //set sentinel after the first element
    node* sentinel = new node;
    sentinel->next = first->next;
    first->next = sentinel;

    //set first after sentinel
    first = sentinel->next;

    node* tmp;
    node* prev;
    node* prev_first = sentinel;

    //for all the values in the cycle
    while( first!= sentinel )
    {
        bool is_unique = true;
        tmp = first->next;
        prev = first;

        //find all the duplicates
        while(tmp != sentinel)
        {
            //if its a duplicate
            if(tmp->val == first->val)
            {
                prev->next = tmp->next;
                delete tmp;
                tmp = prev->next;

                is_unique = false;
            }else//if not just move
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }

        if(!is_unique)//deleting the first element
        {
            prev_first->next = first->next;
            delete first;
            first = prev_first->next;
        }else
        {
            //move first forward
            prev_first = first;
            first = first->next;
        }
        
    }

    //remove the sentinel
    if(sentinel->next == sentinel)
    {
        delete sentinel;
        first = NULL;
    }else
    {
        prev_first->next = sentinel->next;
        delete sentinel;
        first = prev_first->next;
    }
}