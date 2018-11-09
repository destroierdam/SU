#ifndef _DLLIST_H_
#define _DLLIST_H_
#include<cassert>
template<class T>
struct Node
{
    T data;
    Node<T> * next;
    Node<T> * prev;
    Node(const T & _data,Node<T> * _next = nullptr, Node<T> * _prev = nullptr)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

template<class T>
class DLListIterator;

template<class T>
class DLList
{
    Node<T> * first;
    Node<T> * last;
    size_t listSize;

    void copy(const DLList<T> & other) const
    {
        if(other.first == nullptr)
        {
            this->first = nullptr;
            this->last = nullptr;
            return;
        }


        while()
        {
            Node<T> * newNode = new Node<T>()

        }
    }
public:
    DLList()
    {
        first = last = nullptr;
        listSize = 0;
    }
    DLList(const DLList<T> & other)
    {
        copy(other);
    }

    void push_front(const T & newData)
    {
        Node<T> * newNode = new Node<T>(newData, first, nullptr);

        if(first != nullptr)
        {
            first->prev = newNode;
        }
        if(last == nullptr)
        {
            last = newNode;
        }

        first = newNode;

        listSize++;
    }

    void push_back(const T & newData)
    {
        Node<T> * newNode = new Node<T>(newData, nullptr,last);

        if(last != nullptr)
        {
            last->next = newNode;
        }
        if(first == nullptr)
        {
            first = newNode;
        }
        last = newNode;
        listSize--;
    }

    void pop_front()
    {
        assert(first != nullptr);
        Node<T> * toBeDeleted = first;

        first = first->next;

        if(first != nullptr)
        {
            first->prev = nullptr;
        }


        delete toBeDeleted;

        listSize--;
    }

    void pop_back()
    {
        assert(last != nullptr);
        Node<T> * toBeDeleted = last;

        last = last->prev;

        if(last != nullptr)
        {
            last->next = nullptr;
        }

        delete toBeDeleted;

        listSize--;
    }
    T& top() const
    {
        assert(first != nullptr);
        return first->data;
    }
    T& bottom() const
    {
        assert(last != nullptr);
        return last->data;
    }
    size_t size() const
    {
        return this->listSize;
    }

    DLListIterator<T> begin()
    {
        return DLListIterator<T> (*this);
    }

    DLListIterator<T> end()
    {
        return DLListIterator<T> (*this, true);
    }



    friend class DLListIterator<T>;
};

template<class T>
class DLListIterator
{
    Node<T> * cur;
    DLList<T> & myList;
public:
    DLListIterator(DLList<T> & aList,bool toEnd = false):myList(aList)
    {
        if(!toEnd)
        {
            cur = myList.first;
        }
        else
        {
            cur = nullptr;
        }
    }

    T& operator *()
    {
        assert(cur != nullptr);
        return cur->data;
    }

    DLListIterator<T>& operator ++()
    {
        assert(cur != nullptr);
        cur = cur->next;
        return *this;
    }

    DLListIterator<T>& operator --()
    {
        if(cur == nullptr)
        {
            cur = myList.last;
        }
        else
        {
            cur = cur->prev;
        }

        /// ????
        /// assert(cur != nullptr);

        return *this;
    }

    DLListIterator<T>& operator = (DLListIterator<T> other)
    {
        this->cur = other.cur;
        return *this;
    }

    bool operator != (DLListIterator<T> other)
    {
        return this->cur != other.cur;
    }

};








#endif // _DLLIST_H_
