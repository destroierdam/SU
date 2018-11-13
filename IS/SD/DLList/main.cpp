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



    if(l1 == nullptr)
    {
        //Add one element
        l1 = new Node<T>(l2->data, l2->next, nullptr);

        // Add the rest of the elements
        append(l1, l2->next);
    }

    // Go to end of l1
    Node<T> * cur = l1;

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

template<class T>
Node<T> * concatCopy(Node<T> * l)
{
    Node<T> *res = nullptr;

    if(l != nullptr)
    {
        res = new Node<T>(l->data,nullptr,nullptr);

        Node<T> * temp = res;
        while(l->next != nullptr)
        {
            temp->next = new Node<T>(l->next->data);

            cout<<l<<endl;

            l = l->next;

            temp->next->prev = temp;
            temp = temp->next;
        }

    }
    return res;
}

template<class T>
Node<T>* concat(Node<T> * l1, Node<T> * l2)
{
    Node<T> * first = nullptr;
    Node<T> * first2 = nullptr;

    if(l1 == nullptr && l2 == nullptr)
        return nullptr;
    if(l1 == nullptr)
    {
        Node<T> * first = concatCopy(l2);
    }
    else
    {
        first = concatCopy(l1);
        first2 = concatCopy(l2);

        Node<T> * cur = first;

        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = first2;
        if(first2 != nullptr)
        {
            first2->prev = cur;
        }
    }
    return first;

}


void testCount()
{
    Node<int> * elem1 = new Node<int>(1, nullptr,nullptr);
    Node<int> * elem2 = new Node<int>(1, nullptr,elem1);
    Node<int> * elem3 = new Node<int>(2, nullptr,elem2);
    Node<int> * elem4 = new Node<int>(3, nullptr,elem3);
    Node<int> * elem5 = new Node<int>(3, nullptr,elem4);

    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    elem4->next = elem5;

    assert(count(elem1,1) == 2);
    assert(count(elem2,1) == 1);
    assert(count(elem1,2) == 1);
    assert(count(elem1,3) == 2);
}

void testConcatCopy()
{
    Node<int> * elem1 = new Node<int>(1, nullptr,nullptr);
    Node<int> * elem2 = new Node<int>(2, nullptr,elem1);
    Node<int> * elem3 = new Node<int>(3, nullptr,elem2);

    elem1->next = elem2;
    elem2->next = elem3;

    assert(elem1->next->data == 2);
    assert(elem2->next->data == 3);


    Node<int> * copied = concatCopy(elem1);

    assert(copied->prev == nullptr);
    assert(copied->data == 1);
    assert(copied->next != elem2);
    assert(copied->next->prev == copied);
    assert(copied->next->data == 2);
    assert(copied->next->next != elem3);
    assert(copied->next->next->prev != elem2);
    assert(copied->next->next->data == 3);
    assert(copied->next->next->next != elem3);
}

void testRemoveAll()
{
    Node<int> * elem1 = new Node<int>(1, nullptr,nullptr);
    Node<int> * elem2 = new Node<int>(1, nullptr,elem1);
    Node<int> * elem3 = new Node<int>(2, nullptr,elem2);
    Node<int> * elem4 = new Node<int>(3, nullptr,elem3);
    Node<int> * elem5 = new Node<int>(3, nullptr,elem4);

    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    elem4->next = elem5;

    removeAll(elem1,1);

    assert(elem1->data == 2);
    assert(elem1->next == elem3);
    assert(elem1->data == 2);
    assert(elem1->data == 2);

}
int main()
{
    testCount();
    return 0;
}


















