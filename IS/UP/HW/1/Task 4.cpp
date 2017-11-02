#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<n<<endl;
    return 0;
}
