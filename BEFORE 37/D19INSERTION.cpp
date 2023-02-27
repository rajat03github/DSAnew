#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void insertionSort(int n, vector<int> &arr)
{
    int key;
    int j;

    // insertion sort
    // first 0th index ko sorted maan rhe
    // loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        j= i-1;
        // loop for each pass for comparison
        while(j>=0 && arr[j] >  key){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = key;
        

    }
}