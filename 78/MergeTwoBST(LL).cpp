#include <bits/stdc++.h>
using namespace std;

template <typename T>

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
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

void inorder(TreeNode<int> *root, vector<int> &in)
{
    // base case
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void coverintsortedDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    // base case
    if (root == NULL)
        return ;

    // here Head is sub tree linked list head
    coverintsortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;

    coverintsortedDLL(root->left, head);
}

TreeNode<int>* mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            { // insert at end if non null
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}
int countNode(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}
TreeNode<int> *sortedLLtoBST(TreeNode<int> *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
        return NULL;

    TreeNode<int> *left = sortedLLtoBST(head, n / 2);

    TreeNode<int> *root = head;
    root->left = left;

    head = head->next;

    root->right = sortedLLtoBST(head, n - n / 2 - 1);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // step 1 Convert bst into sorted DLL
    TreeNode<int> * head1 = NULL;
    coverintsortedDLL(root1 , head1);
    head1->left = NULL;

    TreeNode<int> * head2 = NULL;
    coverintsortedDLL(root2 , head2);
    head2->left = NULL;

    // step 2 merge sorted ll
    TreeNode<int>* head = mergeLinkedList(head1 , head2);

    // step3 Convert sll into bst 
    return sortedLLtoBST(head , countNode(head));
}
