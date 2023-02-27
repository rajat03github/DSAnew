#include <iostream>
#include<queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool searchInBST(Node * root , int x)
{   

    Node * temp = root ; 

    while(root != NULL)
    {
        if(temp->data == x)
            return true;
        if(temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    // data mila hi nhi loop mei
    return false;

}

    /* recursive way

    // base case 
    if(root == NULL)
        return false;

    if(root->data == x)
        return true; 

    // RECURSIVE CASE 

    if(root->data > x )
        // left part mei milegi
        return searchInBST(root->left , x);
    else
        return searchInBST(root->right , x);
   */