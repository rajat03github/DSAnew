//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
    void createMap(int in[] ,map<int,int> &nodeToIndex , int n  )
    {
        for(int i= 0 ; i < n ; i++ )
        {
         nodeToIndex[in[i]] = i;
        }
        
    }
    /*
    int findPosition(int in[] ,int element , int n  )
    {
        for(int i= 0 ; i < n ; i++ )
        {
            if(in[i] == element )
                return i ; 
        }
        return -1;
    }
    */

    Node * solve(int in[], int post[], int &index , int Inorderstart, int Inorderend , int n , map<int,int> &nodeToIndex)
    {
    // base case 
        if(index < 0 || Inorderstart > Inorderend )

        {
            return NULL;
        }


        int element = post[index--]; 
        Node * root =  new Node(element);
        // int position = findPosition(in , element , n); 
        int position = nodeToIndex[element];


        // recursive calls 
        // in case Of Post Order and InOrder we first build The right sub-Tree becuse Right To left 
        root->right = solve(in , post , index , position+1 , Inorderend , n , nodeToIndex);
        root->left = solve(in , post, index , Inorderstart , position-1 , n, nodeToIndex);

        return root;    
    }
    
Node *buildTree(int in[], int post[], int n) {
    // Code here
        int PostOrderIndex = n-1;
        map<int,int> nodeToIndex; 
        // with map
        createMap(in , nodeToIndex , n);
        
        Node * ans = solve(in, post, PostOrderIndex, 0, n - 1 , n , nodeToIndex);
        return ans;
}
