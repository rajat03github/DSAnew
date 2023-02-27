#include <iostream>
using namespace std;

// heapify
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        // sahi jagah aagaya h
        swap(arr[largest], arr[i]);
        // check more
        heapify(arr, n, largest);
    }
}

// HEAP SORT

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        // step 1: Swap
        swap(arr[size], arr[1]);
        size--;
        // root node is index 1
        heapify(arr, size, 1);
    }
}
int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // heap sort
    heapSort(arr, n);

    cout << "Printing the sorted heap now " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}