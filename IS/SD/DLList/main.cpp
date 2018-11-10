#include <iostream>
#include "DLList.h"
using namespace std;
int main()
{
    DLList<int> l;


    l.push_front(2);
    l.push_front(2);
    l.push_front(2);

    l.push_back(3);
    l.push_back(5);
    l.push_back(5);
    l.push_back(5);
    l.push_back(5);
    l.push_back(5);
    l.push_back(5);

    l.push_back(7);
    l.push_back(7);
    l.push_back(7);
    l.push_back(7);


    return 0;
}
