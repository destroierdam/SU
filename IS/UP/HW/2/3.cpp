#include<iostream>
using namespace std;
int main()
{
    int r,k,a[16][16];
    int i,j,ans[16][16];
    cin>>r>>k;
    for(i=0;i<r;i++)
    {
        for(j=0;j<k;j++)
        {
            cin>>a[i][j];
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<k;j++)
        {
            ans[i][j]=a[i][j]*r*k;
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<k;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
