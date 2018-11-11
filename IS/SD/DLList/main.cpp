#include <iostream>
#include <cassert>
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

template<class T>
void append(Node<T> *& l1, Node<T> * l2)
{
    if(l2 == nullptr)
    {
        return;
    }

    // Go to end of l1
    Node<T> * cur = l1;

    if(l1 == nullptr)
    {
        //Add one element
        l1 = new Node<T>(l2->data, nullptr, l2->next);

        // Add the rest of the elements
        append(l1, l2->next);
    }

    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    // cur points to the last element of l1

    while(l2 != nullptr)
    {
        cur->next = new Node<T>(l2->data, l2, cur);

        cur = cur->next;
        l2 = l2->next;
    }
}

int main()
{
    Node<int> * elem1 = new Node<int>(1, nullptr,nullptr);
    Node<int> * elem2 = new Node<int>(2, elem1,nullptr);
    Node<int> * elem3 = new Node<int>(3, elem2,nullptr);

    elem1->next = elem2;
    elem2->next = elem3;


    Node<int> * elem4 = new Node<int>(1, nullptr,nullptr);
    //Node<int> * elem5 = new Node<int>(2, elem4,nullptr);
    //Node<int> * elem6 = new Node<int>(3, elem5,nullptr);

    //elem4->next = elem4;
    //elem5->next = elem4;

    assert(elem3->next = elem4);
    assert(elem4->prev = elem1);
    assert(elem1->next->data = elem4->data);
    return 0;
}


















