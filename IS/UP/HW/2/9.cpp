#include<iostream>
using namespace std;
int sumDig(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    if(n%sumDig(n)==0)
        cout<<"Deli se"<<endl;
    else
        cout<<"Ne se deli"<<endl;
    return 0;
}
