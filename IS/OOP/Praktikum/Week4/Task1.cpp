#include<iostream>
using namespace std;

// принтира елементите на масив
template <class T>
void print(const T* arr,size_t sz)
{
    size_t i;
    for(i=0;i<sz;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// връща индекса на най-малкия елемент в масив
template <class T>
int minElIdx(const T* arr,size_t sz)
{
    size_t idx=0,i;
    for(i=1;i<sz;i++)
    {
        if(arr[i]<arr[idx])
        {
            idx=i;
        }
    }
    return idx;
}

// връща най-големия елемент в масив
template <class T>
T maxEl(const T* arr,size_t sz)
{
    size_t idx,i;
    for(i=1;i<sz;i++)
    {
        if(arr[i]>arr[idx])
        {
            idx=i;
        }
    }
    return arr[idx];
}

// връща средносатистическото на елементите от един масив
template <class T>
T avg(const T* arr,size_t sz)
{
    size_t i;
    T avg;
    for(i=0;i<sz;i++)
    {
        avg+=arr[i];
    }
    avg/=sz;
    return avg;
}
int main()
{
    int arr[5]={2,3,4,5,6};
    print<int>(arr,5);


    minElIdx<int>(arr,5);

    cout<<minElIdx<int>(arr,5)<<endl;
    cout<<maxEl<int>(arr,5)<<endl;

    return 0;
}
/*

Да се напише шаблонна функция, която:

*/
