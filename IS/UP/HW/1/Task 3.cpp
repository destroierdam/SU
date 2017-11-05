#include<iostream>
using namespace std;
int main()
{
    unsigned long long int n;
    int cnt=0;
    cin>>n;
    while(n!=0)
    {
        n/=10;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
