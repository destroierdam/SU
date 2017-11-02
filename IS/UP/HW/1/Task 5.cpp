#include<iostream>
using namespace std;
int main()
{
    int i,d1,d2,d3;
    for(i=100;i<=999;i++)
    {
        d3=i%10;
        d2=i/10%10;
        d1=i/100;
        if(d1!=d2&&d2!=d3&&d1!=d3)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
