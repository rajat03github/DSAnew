#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        { // right
            s = mid + 1;
        }
        else
        { // left
            e = mid - 1;
        }
        // updating mid
        mid = s + (e - s) / 2;
    }
    return ans;
}
// LAST OCC
int lastOcc(int arr[], int n, int key)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        { // right
            s = mid + 1;
        }
        else
        { // left
            e = mid - 1;
        }
        // updating mid
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int even[5] = {1, 2, 3, 3, 5};

    cout << " FIRST OCCURENCE OF 3 is at INDEX: " << firstOcc(even, 5, 3) << endl;
    cout << " LAST OCCURENCE OF 3 is at INDEX: " <<lastOcc(even, 5, 3) << endl;

    return 0;
}