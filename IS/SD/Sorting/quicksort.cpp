#include<iostream>
#include<algorithm> // swap()
using namespace std;

template<class T>
int partitionArr(T arr[], int left, int right,const T& pivot) // working
{
    while(left <= right)
    {
        // Move left to the leftmost element bigger than or equal to the pivot element
        while(arr[left] < pivot)
        
        {
            left++;
        }

        // Move right to the rightmost element less than or equal to the pivot element
		
        while(pivot < arr[right]) 
        {
            right--;
        }

        if(left <= right)
        {
            swap(arr[left++], arr[right--]);
        }
    }
    // Return partition index
    return left;
}

template<class T>
void quicksort(T arr[],int left,int right)
{
    if(left < right)
    {
        // Choose middle item for pivot

        T pivot = arr[left + (right - left) / 2]; // working

        int partIndex = partitionArr(arr,left,right,pivot);

        quicksort(arr, left, partIndex-1);

        quicksort(arr,partIndex, right);
    }
}

int main()
{
    int arr[] = {60, 14, 6, 43, 32, 14, 70, 94, 80, 75, 96, 88, 57, 40 ,50, 54, 112, 112, -15};

    size_t sz =  sizeof(arr)/sizeof(int);

    quicksort(arr, 0, sz-1);

    for(int i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
