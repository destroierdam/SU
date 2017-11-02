#include<iostream>
using namespace std;
int main()
{
    unsigned long long int n;
    int br=0;
    cin>>n;
    while(true)
    {
        if(n!=0)
        {
            n/=10;
            br++;
        }
        else break;
    }
    cout<<"Number of digits : "<<br<<endl;
    return 0;
}
