/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

void Inorder(BinaryTreeNode<int> *root , int &count) //LNR
{
    // base case 
    if(root == NULL )
        return;

    Inorder(root->left , count);  //left 
    
    //     leaf node 
   if(root->left == NULL && root->right == NULL ){
       count ++ ; 
    }
     
 
    Inorder(root->right , count); //right
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0 ;
    Inorder(root , count );
    return count ; 
    
    
}


// O(N) = time complex N nodes of tree