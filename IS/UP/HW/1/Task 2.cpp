#include<iostream>
using namespace std;
int main()
{
    int n=0,sum=0,t;
    while(true)
    {
        cin>>t;
        if(t<1) break;

        sum+=t;
        n++;
    }
    double avg=(double)sum/n;

    cout<<"Number : "<<n<<endl;
    cout<<"Sum : "<<sum<<endl;
    cout<<"Average : "<<avg<<endl;
    return 0;
}
