#include<iostream>
#include<cmath>
using namespace std;
void ans(int n,int k)
{
    int br=0,maxbr=0,i=0;
    int num[1024];
    while(n)
    {
        if(n%2==0)
        {
            br++;
        }
        else
        {
            maxbr=max(br,maxbr);
            br=0;
        }
        num[i++]=n%2;
        n/=2;
    }
    int sz=i;
    for(i=sz-1;i>=0;i--)
    {
        cout<<num[i];
    }
    cout<<" - broi posledovatelni nuli "<<min(maxbr,k)<<endl;
}
int main()
{
    int n,k;
    cin>>n>>k;
    ans(n,k);
    return 0;
}
