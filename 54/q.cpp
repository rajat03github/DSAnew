/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* sortList(Node *head)
{
    // Write your code here.
//     making count 
    int zero = 0;
    int one = 0 ; 
    int two = 0;
    
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0 )
            zero++ ; 
        else if(temp ->data == 1)
            one++;
        else if(temp -> data == 2)
            two++;
        
        temp = temp-> next ; 
      
    }
    
    temp = head ; 
    while( temp != NULL ){
        
    
        if(zero != 0 ){
            temp ->data = 0;
            zero--;      
        }
        else if(one != 0){
            temp ->data = 1;
            one--;
            
        }
        else if(two != 0){
            temp -> data = 2;
            two -- ;
        }
        temp = temp-> next;
    }  
    return head;
}


// NON DATA REPLACE
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
void populate(Node * &tail , Node * curr){
    
    tail -> next = curr;
    tail = curr ; 

}

Node* sortList(Node *head)
{
    // Write your code here.
//     create dummies nodes
    
    Node * zeroHead = new Node(-1);
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node (-1);
    Node * oneTail = oneHead ;
    Node * twoHead = new Node(-1);
    Node * twoTail = twoHead ; 
    
    Node * curr = head ;
    
//     created  seprate list of zero one two 
    
    while ( curr != NULL){

        int value = curr -> data ; 
        if(value == 0 ){
            populate(zeroTail, curr);
            
        }
        else if ( value == 1)
        {
            populate(oneTail , curr) ; 
        }
        else if( value == 2)
        {
            populate(twoTail , curr) ; 
        }
        
        curr = curr-> next;
    }
    
//     MERGING 3 dummies 
    
    if(oneHead -> next != NULL ) //one list non empty 
    {
        zeroTail -> next = oneHead -> next ;
    }
    else //one list is empty 
    {
        zeroTail -> next = twoHead -> next ; 
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

//    setup head
    head = zeroHead -> next ; 
    
//      delete dummies 
    delete zeroHead;
    delete oneHead ;
    delete twoHead ;
    
    return head;
}

