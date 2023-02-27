LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head== NULL || head-> next == NULL ){
        return head;
    }
    // Write your code here
    LinkedListNode* prev = NULL:
    LinkedListNode* curr = head;
    LinkedListNode* forward = NULL;
    
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = forward;
    }
    return prev;
}

// RECURSIVE
void reverse(LinkedListNode* &head ,LinkedListNode*curr , LinkedListNode*prev ){
//     base case 
    if(  curr == NULL ){
        head = prev;
        return ;
    }
    LinkedListNode*forward  = curr->next ; 
    reverse(head, forwared , curr);
    curr->next = prev;
    
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode*cur = head; 
    LinkedListNode*prev = NULL;
    reverse(head, curr, prev );
    return head;
    // Write your code here
}

// approcah 2 
Node * reverse ( Node * head)
{
    if ( head == NULL || head.next == NULL){
        return head;
    }
     Node * chotahead = reverse(head.next);
    head.next.next = head ; 
    head .next = NULL ; 

    return chotahead;

}

// MIDdLE

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/
Node*getMid(Node * head ){
    if(head == NULL || head->next == NULL )
    {
        return NULL ; 
    }
//     2 nodes 
    if( head->next->next == NULL){
        return head->next;
    }
    Node * slow = head ;
    Node * fast = head-> next ; 
    
    while ( fast != NULL ){
        fast =  fast-> next; 
        if(fast != NULL){
          fast =  fast-> next;    
        }
        slow = slow-> next ; 
    }
    return slow;
}



int getLen(Node * head){

    int len = 0;
    while( head != NULL ){
        len ++;
        head = head->next;
    }
    return len;
}
Node *findMiddle(Node *head) {
    
    return getMid(head);
    // Write your code here
  /*  int len = getLen(head);
    int ans = (len / 2 ) ;
    
    Node* temp = head;
    int cnt = 0 ;
     
    while(cnt < ans ){
        temp = temp->next ;
        cnt++;
    }
    return temp;*/
}