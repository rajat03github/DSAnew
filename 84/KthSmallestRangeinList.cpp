#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->col = col;
        this->row = row;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    //    create min amd max;
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // create min heap
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    while (!minHeap.empty())
    {
        node *temp = minHeap.top();
        minHeap.pop();

        int col = temp->col;
        int row = temp->row;


        mini = temp->data;

        // update range
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }
        // check if next Element exists
        if (temp->col + 1 < n)
        {
            int NextEle = a[temp->row][temp->col + 1];
            maxi = max(maxi, NextEle);
            minHeap.push(new node(NextEle, temp->row, temp->col + 1));
        }
        else
        {
            // next element not exists
            break;
        }
    }
    // for [3,9] = 9-3 +1 = 7 ; because of 0th index
    return (end - start + 1);
}