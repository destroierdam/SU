#include<iostream>
using namespace std;
int main()
{
    int i,j,n,arr[128][2];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }

    for(i=0;i<n;i++)
    {
        cout<<arr[i][0]<<" / "<<arr[i][1]<<" = ";
        cout<<arr[i][0]*100/arr[i][1]<<"%"<<endl;
    }
    return 0;
}
