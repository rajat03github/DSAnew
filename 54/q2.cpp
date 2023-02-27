// merginng two sorted linked list 

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/



Node<int>* solve(Node<int>* first, Node<int>* second)
{
//     if only one element is present if first link
    if(first-> next == NULL ){
        first -> next = second ;
        return first;
    }
    
    Node<int>* curr1 = first ; 
    Node<int>* next1 = curr1-> next;
    Node<int>* curr2 = second ; 
    Node<int>* next2 = curr2 -> next;
    
    while (next1 != NULL && curr2 != NULL )
    {
        if( (curr2 -> data >= curr1 -> data) 
              && (curr2 -> data <= next1 ->data))
        {
//             nodes addition
            curr1 -> next = curr2 ;
            next2 = curr2 -> next ; 
            curr2-> next = next1; 
            
//             update
            curr1 = curr2 ; //curr 2 because intially 2 was curr 2; 
            curr2 = next2 ;
            
        }
        else //aesa element jo unke bich nahi dal sakta 
        {
            //curr1 and next1 ko aage badhao
            curr1 = curr1 -> next;
//             curr1 = next1; //same as just above line
            next1 = next1 -> next; 
            
            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
            
        }
    }
    
    return first;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
   if ( first == NULL )
       return second;
    if(second == NULL )
        return first; 
    
    if(first -> data <= second -> data){
       return solve(first, second);
    }
    else //first ka data badha hai
    {
          return   solve(second , first);   
    }
    
    
}
