#include <iostream>
#include <queue>
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

Node *insertIntoBST(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
        // insert at right
        root->right = insertIntoBST(root->right, data);
    else
        // insert at left
        root->left = insertIntoBST(root->left, data);

    return root;
}

void levelOrderTraversal(Node *root)
{
    // we use queue
    queue<Node *> q;
    q.push(root); // only root because Node * type
    // for seperator of levels
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            // q.front = NULL means poorana lvl complete travese ho chuka hai
            cout << endl;

            if (!q.empty())
            {
                // queue mei still kuch element padha hai
                q.push(NULL);
            }
        }

        else
        {
            // IF NON NULL
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void Inorder(Node *root) // LNR
{
    // base case
    if (root == NULL)
        return;

    Inorder(root->left);       // left
    cout << root->data << " "; // Node
    Inorder(root->right);      // right
}

void Preorder(Node *root) // NLR
{
    // base case
    if (root == NULL)
        return;

    cout << root->data << " "; // Node
    Inorder(root->left);       // left
    Inorder(root->right);      // right
}

void Postorder(Node *root) // LRN
{
    // base case
    if (root == NULL)
        return;

    Inorder(root->left);       // left
    Inorder(root->right);      // right
    cout << root->data << " "; // Node
}

Node *minValue(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node *maxValue(Node *root)
{
    Node *temp = root;

    while (temp->right != NULL)
        temp = temp->right;

    return temp;
}

Node *deleteFromBST(Node *root, int val)

{
    // base case
    if (root == NULL)
        return root;
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        /*** 1 CHILD CASE ***/

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete temp;
            return temp;
        }

        // Right child
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete temp;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        // Left part mei jaao
        root->left = deleteFromBST(root->left, val);
        return root;
    }

    else
    {
        // right part mei jaao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{
    // 50 20 70 10 30 90 110 -1

    Node *root = NULL;

    cout << "Enter data to create BST " << endl;
    takeInput(root);

    cout << "Printing the BST ~" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Print Inorder ~" << endl;
    Inorder(root);
    cout << endl;

    cout << "Print PreOrder ~" << endl;
    Preorder(root);
    cout << endl;

    cout << "Print Postorder ~" << endl;
    Postorder(root);
    cout << endl;

    cout << "Min Value is : " << minValue(root)->data << endl;
    cout << "Max Value is : " << maxValue(root)->data << endl;

    root = deleteFromBST(root, 50);

    cout << "After Deletion ~~~ " << endl;

    cout << "Printing the BST ~" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Print Inorder ~" << endl;
    Inorder(root);
    cout << endl;

    cout << "Print PreOrder ~" << endl;
    Preorder(root);
    cout << endl;

    cout << "Print Postorder ~" << endl;
    Postorder(root);
    cout << endl;

    cout << "Min Value is : " << minValue(root)->data << endl;
    cout << "Max Value is : " << maxValue(root)->data << endl;

    return 0;
}