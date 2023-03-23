//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Node // for Huffman tree
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    void preOrder(Node *root, vector<string> &ans, string temp)
    {
        // base case
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        preOrder(root->left, ans, temp + '0');
        preOrder(root->right, ans, temp + '1');
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int i = 0; i < N; i++)
        {
            Node *temp = new Node(f[i]);

            pq.push(temp);
        }
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->data + right->data);

            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node *root = pq.top();
        vector<string> ans;
        string temp = ""; // ~To add 0 || 1

        preOrder(root, ans, temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends