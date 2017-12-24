#include<iostream>
#define ulli unsigned long long int
using namespace std;
ulli fib(ulli n)
{
    int i,fib0=0,fib1=1,fibnew=1;
    if(n==0||n==1) return n;
    for(i=2;i<=n;i++)
    {
        fib0=fib1;
        fib1=fibnew;
        fibnew=fib0+fib1;
    }
    return fib1;
}
int main()
{
    ulli n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
