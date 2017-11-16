#include<iostream>
using namespace std;
int main()
{
    int a[1024],x,i,j,n;
    cout<<"Array length: ";
    cin>>n;
    cout<<"\nArray: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"X= ";
    cin>>x;
    cout<<endl;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            for(j=i;j<n-1;j++)
            {
                a[j]=a[j+1];
            }
            a[j]=-1;
            break;
        }
    }
    cout<<"Array : ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
