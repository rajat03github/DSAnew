#include<iostream>
#include<map>
using namespace std;

class Node {

  public:
  int data;
  Node * next;  

//   constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
// destr
~Node(){
  // for head temp
  int value = this->data;
  if(this->next != NULL)
  {
    delete next;
    next = NULL;
  }
  cout<<"mem is free for node with data "<< value <<endl;
}

};

void insertNode(Node* &tail , int element , int data){
    // empty
    if(tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
    // non empty 
    //  assume that element is present in list

    Node * curr = tail ;
    while(curr->data != element){
        curr = curr->next;
    }
        
        // element mil gaya and curr is elemnt node
        Node * temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node * tail ){

    Node * temp = tail ; 
    // cout<<tail->data<<" ";
    if(tail == NULL)
    {
        cout<<"List is empty ";
        return;
    }
    do
    {/* code */
        cout<<tail->data <<" ";
        tail = tail->next; 
    } while (tail != temp);
    
    // while(tail->next != temp ){
    //     cout<<tail->data <<" ";
    //     tail = tail->next;
    // }
    cout<<endl;
}

void deleteNode(Node * &tail ,int value )
{
    // empty lise
    if(tail == NULL)
{
    return;
}
else{
    // value is present 
    Node* prev = tail ; 
    Node* curr = prev->next;

    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next ; 

// 1 Node linked list 
if(curr == prev){
    tail = NULL;
}
// > = 2 Node linked list
    if(tail == curr){
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}
}

bool isCircularList(Node * head )
{
    // empty list 
    if(head == NULL ){
        return true;
}
    Node * temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head ){
        return true;
    }
    return false;

}

// code for detect loop

bool detectLoop(Node * head){

    if(head == NULL){
        // empty list 
        return false ; 
    }
    // with map 
    map<Node *, bool > visited ; 

    Node * temp = head ; 
    while(temp != NULL){

        // cycle is present 
        if(visited[temp] == true) {
            
               return true ; 
            // return 1;     

        }
        visited[temp] = true; 
        temp = temp->next;
    }

    return false;
}


int main(){
    
    Node * tail = NULL;

    insertNode(tail , 5 , 3);
    print(tail);

    insertNode(tail ,3, 5);
    print(tail);

    insertNode(tail ,5, 15);
    print(tail);
   
    insertNode(tail ,3, 365);
    print(tail);

    insertNode(tail ,365, 55555555);
    print(tail);


    deleteNode(tail,3);
    print(tail);

    if(isCircularList(tail)){
        cout<<"Linked List is circular "<<endl;
    }

    else{
        cout<<"List is not circular" ; 
    }
    return 0; 
}