#include<iostream>
#include<algorithm> // swap()
using namespace std;

// Switches between pivot representing A COPY of the pivot element, and pivot representing the INDEX of the pivot element
#define pivotIsIndex 0
// pivotIsIndex 1 doesn't work, but 0 works

template<class T>
#if pivotIsIndex
int partitionArr(T arr[], int left, int right, int pivot) // not working
#else
int partitionArr(T arr[], int left, int right,const T& pivot) // working
#endif // pivotIsIndex
{
    while(left <= right)
    {
        // Move left to the leftmost element bigger than or equal to the pivot element

        #if pivotIsIndex
        while(arr[left] < arr[pivot]) // not working
        #else
        while(arr[left] < pivot) // working
        #endif // pivotIsIndex
        {
            left++;
        }

        // Move right to the rightmost element less than or equal to the pivot element

        #if pivotIsIndex
        while(arr[pivot] < arr[right]) // not working
        #else
        while(pivot < arr[right]) // working
        #endif // pivotIsIndex
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

        #if pivotIsIndex
        int pivot = left + (right - left) / 2; // not working
        #else
        T pivot = arr[left + (right - left) / 2]; // working
        #endif // pivotIsIndex

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
