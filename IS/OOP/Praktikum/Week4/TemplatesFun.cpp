#include<iostream>
using namespace std;
class MyClass
{
public:
    int *asd;
    MyClass()
    {
        asd = new int[3] {1,2,3};
        cout<<asd<<" was created"<<endl;;
    }
    ~MyClass()
    {
        cout<<asd<<" was deleted"<<endl;;
        delete[] asd;
    }
    void printElements() const
    {
        for(int i=0;i<3;i++)
            cout<<asd[i]<<" ";
    }
    int& operator[](int idx)
    {
        return asd[idx];
    }
    bool operator>(const MyClass& other) const
    {
        for(int i=0;i<3;i++)
            if(asd[i]>=other.asd[i]) return false;
        return true;
    }

;

};
// принтира елементите на масив
template <class T>
void print(const T* arr,size_t sz)
{
    size_t i;
    for(i=0;i<sz;i++)
    {
        arr[i].printElements();
        cout<<" ";
    }
    cout<<endl;
}

// връща най-големия елемент в масив
template <class T>
T maxEl(const T* arr,size_t sz)
{
    size_t idx=0  ,i;
    for(i=1;i<sz;i++)
    {
        if(arr[i]>arr[idx])
        {
            idx=i;
        }
    }
    return arr[idx];
}

int main()
{
    MyClass arr[5];
    print<MyClass> (arr,5);

    arr[1][1]=521;

    print<MyClass> (arr,5);

    maxEl(arr,5);

    return 0;
}

/*

Да се напише шаблонна функция, която:

*/
/*
#include<iostream>
using namespace std;
template <class T>
class MyClass
{
public:
    T *arr = new T[5] {2,3,4,5,6};
    MyClass(){};
    ~MyClass()
    {
        for(int i=0;i<5;i++)
            cout<<arr[i]<<" ";
        cout<<"was destroyed"<<endl;
        cout<<"Address of ptr: "<<arr<<endl;
    }
    void printArr()
    {
        for(int i=0;i<5;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    //friend int minElIdx(const T* arr,size_t sz)
};

// принтира елементите на масив
template <class T>
void print(T*& arr,size_t sz)
{
    arr.printArr();
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
    //int *arr= new int[5] {2,3,4,5,6};
    //int arr[5]={2,3,4,5,6};

    MyClass<int> a;

    print< MyClass<int> >(a,5);


    cout<<minElIdx<int>(a,5)<<endl;

    print<int>(a,5);

    delete[] a;
    //cout<<minElIdx<int>(arr,5)<<endl;
    //cout<<maxEl<int>(arr,5)<<endl;

    return 0;
}
/*

Да се напише шаблонна функция, която:

*/

