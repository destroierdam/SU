#include<iostream>
using namespace std;
int main()
{
    int n,i,d1,d2,sum=0;
    cin>>n;
    for(i=n;i>=7;i--)
    {
        if(i%7==0)
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
