#include<iostream>
using namespace std;
int main()
{
    int n,i,d1,d2,sum=0;
    cin>>n;
    for(i=10;i<=n;i++)
    {
        d1=i%10;
        d2=i/10%10;
        sum+=d1+d2;
    }
    cout<<sum<<endl;
    return 0;
}
