#include<iostream>
using namespace std;
int main()
{
    int i,br=0;
    for(i=1;br<4;i++)
    {
        if((i%2==1)&&(i%3==2)&&(i%4==3)&&(i%5==4)&&(i%6==5)&&(i%7==6)&&(i%8==7)&&(i%9==8))
        {
            cout<<i<<endl;
            br++;
        }
    }
    return 0;
}
