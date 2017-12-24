#include<iostream>
using namespace std;
bool equalDig(int i)
{
    int cur,prev=i%10;
    i/=10;
    while(i)
    {
        cur=i%10;
        if(cur!=prev)
        {
            return false;
        }
        i/=10;
    }
    return true;
}
int main()
{
    int i;
    for(i=1;;i++)
    {
        if(equalDig(i*18))
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
