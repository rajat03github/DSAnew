#include <bits/stdc++.h>
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        // Write your code here.
        //         queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "queue is full ";
            return false;
        }
        else if (front == -1) // first elent to push
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) // to maintain cycle nature
        {
            rear = 0;
            //             arr[rear ] =value ;
        }
        else
        { // normal flow
            rear++;
            //             arr[rear ] = value ;
        }
        // push
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // Write your code here.
        if (front == -1) // to check empty
        {
            cout << "queue is empty ";
            return -1;
        }
        int ans = arr[front];
        arr[front];

        if (front == rear) // single elemnt is prst
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        //         normal flow
        else
        {
            front++;
        }
        //         pop
        return ans;
    }
};