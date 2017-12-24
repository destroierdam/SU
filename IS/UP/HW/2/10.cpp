#include<iostream>
#include<cmath>
#define ControlPrint 0
using namespace std;
int main()
{
    int i,n=49,k=15;
    cin>>n>>k;
    int roomsNeeded=ceil((double)n/k);

    int pplInRoom=n/roomsNeeded;

    int rem=n-pplInRoom*roomsNeeded;

    #if ControlPrint
    cout<<"Rooms needed : "<<roomsNeeded<<endl;
    cout<<"People in room : "<<pplInRoom<<endl;
    cout<<"Remaining : "<<rem<<endl;
    #endif


    for(i=0;i<roomsNeeded;i++)
    {
        cout<<pplInRoom+(rem?1:0)<<" ";
        if (rem!=0)
            rem--;
    }
    cout<<endl;
    return 0;
}
