#include <iostream>
#include "DLList.h"
using namespace std;
int main()
{
    DLList<int> l;
    DLListIterator<int> it(l);

    l.push_front(5);



    cout<<l.top()<<endl;

    DLList<int> lCopy(l);
    DLListIterator<int> lCopyIt(lCopy);


    for(lCopyIt = lCopy.begin();lCopyIt != lCopy.end();++lCopyIt)
    {
        cout<<*it<<endl;
    }

    return 0;
}
