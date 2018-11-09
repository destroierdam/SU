#include <iostream>
#include "DLList.h"
using namespace std;
int main()
{
    DLList<int> l;
    
    l.push_back(2);
    l.push_back(3);
    l.push_back(5);
    l.push_back(7);

    

    DLList<int> l2(l);

    DLListIterator<int> it(l2);


    
    it++;

    return 0;
}
