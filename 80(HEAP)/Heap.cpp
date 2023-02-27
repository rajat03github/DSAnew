#include <iostream>
#include <queue>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            // MAX HEAP
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    void print()
    {
        // in heap the arr 0th index is empty
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        // last value ko sabse upr put krre
        arr[1] = arr[size];
        size--;

        // take root node to its correct postion
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
                return;
        }
    }
};

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
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.insert(52);

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    // heapcreation
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the heap now " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heap sort
    heapSort(arr, n);

    cout << "Printing the sorted heap now " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // PRIORITY QUEUE IS basic heap data structure
    cout << "using priority queue here " << endl;

    // maxheap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    // priority queue uses as top
    cout << "element on top " << pq.top() << endl;

    pq.pop();
    cout << "element on top " << pq.top() << endl;

    cout << "size is " << pq.size() << endl;

    if (pq.empty())
        cout << "Is Empty";
    else
        cout << "Not empty ";

    // PRIORITY QUEUE FOR MIN HEAP
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(4);
    minpq.push(2);
    minpq.push(5);
    minpq.push(3);

    // priority queue uses as top
    cout << "element on top " << minpq.top() << endl;

    minpq.pop();
    cout << "element on top " << minpq.top() << endl;

    cout << "size is " << minpq.size() << endl;

    if (minpq.empty())
        cout << " minpq Is Empty";
    else
        cout << " minpq Not empty ";

    return 0;
}