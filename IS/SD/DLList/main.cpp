#include <iostream>
#include "DLList.h"
using namespace std;

template<class T>
int count(Node<T> * l,const T & x)
{
    int br = 0;

    while(l != nullptr)
    {
        br += (x == l->data);
        l = l->next;
    }
    return br;
}

Node<int>* range(int x, int y)
{
    assert(x<=y);

    Node<int> * beginning = new Node<int>(x++, nullptr, nullptr);

    Node<int> * cur = beginning;

    while(x<=y)
    {
        cur->next = new Node<int>(x++, nullptr, cur);
        cur = cur->next;
    }

    return beginning;
}

template<class T>
void removeAll(Node<T>*& l, const T & x)
{
    if(l == nullptr)
        return;

    Node<T> * cur = l;

    while(cur != nullptr)
    {
        if(cur->data == x)
        {
            Node<T> * toBeDeleted = cur;
            cur = cur->next;


            // Ensure forward pointer
            if(cur != nullptr)
            {
                cur->prev = toBeDeleted->prev;
            }

            // Ensure deletion pointer by head of list
            if(toBeDeleted == l)
            {
                l = l->next;
            }

            // Ensure backward pointer
            if(toBeDeleted->prev != nullptr)
            {
                toBeDeleted->prev->next = cur;
            }

            delete toBeDeleted;
            toBeDeleted = nullptr;
        }
        else
        {
            cur = cur->next;
        }
    }
}
int main()
{

    return 0;
}


















