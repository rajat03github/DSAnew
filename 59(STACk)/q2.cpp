#include <bits/stdc++.h>
using namespace std;
class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        // Write your code here.
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        // atleast one empty space prst
        if (top2 - top1 > 1) // because top2 is size
        {
            top1++;
            arr[top1] = num;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (top2 - top1 > 1) // because top2 is size
        {
            top2--;
            arr[top2] = num;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // atleast one element is prst
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        // atleast one element is prst
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};
