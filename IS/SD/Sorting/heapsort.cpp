#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void heapify(int arr[], int sz, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < sz && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < sz && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, sz, largest);
    }
}

void heapsort(int arr[], int sz)
{
    for (int i = sz/ 2 - 1; i >= 0; i--)
        heapify(arr, sz, i);

    // One by one extract an element from heap
    for (int i=sz-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {60, 14, 6, 43, 32, 14, 70, 94, 80, 75, 96, 88, 57, 40,50, 54, 112, 112, -15};
    //int arr[] = {1,8,7,6,5,4,3,2,1};

    size_t sz =  sizeof(arr)/sizeof(int);

    heapsort(arr, sz);

    for(int i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
