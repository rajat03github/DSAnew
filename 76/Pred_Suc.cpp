#include <bits/stdc++.h>

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // find key

    BinaryTreeNode<int> *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data; // possible
            temp = temp->left;
        }
        else
        {
            pred = temp->data; // possible
            temp = temp->right;
        }
    }

    // find pred and succ

    // pred = left mei max
    BinaryTreeNode<int> *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ = right mei min
    BinaryTreeNode<int> *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }


    // return {pred , succ};

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}
