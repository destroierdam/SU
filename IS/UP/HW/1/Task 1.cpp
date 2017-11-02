#include<iostream>
using namespace std;
int main()
{
    int n,i,sum=0,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        sum+=t;
    }
    cout<<sum<<endl;
    return 0;
}
