#include<iostream>
using namespace std;
int main()
{
    int arr[6][6]=
{11,12,13,14,15,16,
21,22,23,24,25,26,
31,32,33,34,35,36,
41,42,43,44,45,46,
51,52,53,54,55,56,
61,62,63,64,65,66};

    int i,j,sum=0,ans=0;

    for(i=0;i<36;i++)
    {
        if(arr[i/6][i%6]%2)
        {
            cout<<arr[i/6][i%6]<<", ";
            sum+=arr[i/6][i%6];
        }

        if(i%6==5)
        {
            cout<<"Suma na reda "<<sum<<endl;
            ans+=sum;
            sum=0;
        }
    }

    cout<<"Suma na elementite "<<ans<<endl;
    return 0;
}
