 #include<iostream>
 #include<queue>
 using namespace std;

class node{

    public:
    int data ; 
    node * left ;
    node * right ;


    node(int data ){
        this->data = data ;
        this->left = NULL ; 
        this->right = NULL;
    }
};

node * buildTree(node * root) 
{
    cout<<"Enter the data : "<<endl;
    int data ; 
    cin>>data ;
    root = new node(data);

    if(data == -1 )
        return NULL;
    
    cout<<"Enter the data for inserting for left node: "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for inserting for right node: "<<data <<endl;
    root->right = buildTree(root->right);
     
    return root;
}

void levelOrderTraversal(node  * root ){
    // we use queue
    queue<node*> q ; 
    q.push(root); //only root because node * type
    // for seperator of levels
    q.push(NULL);

    while(!q.empty() ){
        node * temp = q.front() ; 
        
        q.pop(); 

        if(temp == NULL )
        {
            // q.front = NULL means poorana lvl complete travese ho chuka hai
            cout<<endl;

            if(!q.empty()){
                // queue mei still kuch element padha hai 
                q.push(NULL);
            }
        }

        else
        {
                // IF NON NULL
            cout<< temp->data <<" ";
            if(temp->left ) {
                q.push(temp->left);
            }

            if(temp->right ) {
                q.push(temp->right);
            }

        }

    }
}

void Inorder(node * root ) //LNR
{
    // base case 
    if(root == NULL )
        return;

    Inorder(root->left);  //left 
    cout<<root->data<<" "; //node 
    Inorder(root->right); //right

}

void Preorder(node * root ) //NLR
{
    // base case 
    if(root == NULL )
        return;

    cout<<root->data<<" "; //node 
    Inorder(root->left);  //left 
    Inorder(root->right); //right

}

void Postorder(node * root ) //LRN
{
    // base case 
    if(root == NULL )
        return;

    Inorder(root->left);  //left 
    Inorder(root->right); //right
    cout<<root->data<<" "; //node 

}

void buildfromLevelOrder(node * &root ){
    
    queue<node *>q ; 
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root) ; 

    while(!q.empty())
    {
        node * temp  = q .front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            // not null
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            // not null
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

 
int main(){
 
    node * root = NULL;


    buildfromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);



    /*
    // creating a tree 
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 ~i/p

    // LEVEL ORDER PRINT 
    cout<<"Printing the data for binary_Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Travesal is: ";
    Inorder(root);
    cout<<endl;

    cout<<"Preorder Travesal is: ";
    Preorder(root);
    cout<<endl;
    
    cout<<"Postorder Travesal is: ";
    Postorder(root);
    cout<<endl;
    */    


    return 0;
 }