#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node* next ; 
    // constructor
    Node(int data ){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    // desc
    ~Node(){
  // for head temp
  int value = this->data;
  if(this->next != NULL){
    delete next;
    this->next = NULL;
  }
  cout<<"mem is free for node with data "<< value <<endl;
}
};
void print(Node* head){
    Node* temp = head ;
    while (temp != NULL)
    {
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
    

}
int  getLenght(Node*head)
{
    int len = 0;
     Node* temp = head ;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertHead(Node* &head, int data){

    if(head==NULL)
    {
    Node*temp = new Node(data);
    head = temp;
    }

    else{

  // new node create
  Node*temp = new Node(data);
  temp->next = head;
  head->prev = temp;
  head = temp ;

    }
  
}


void InsertTail(Node* &tail , int data){
    if (tail== NULL)
    {
    Node*temp = new Node(data);
    tail = temp;       
    }
    else{
        // new node create
    Node*temp = new Node(data);
    tail->next = temp;
    temp->prev = tail ; 
    tail = temp;

    }

}

void insertPosi(Node* &head, int position , int data, Node* &tail){

  // insert at head
  if(position== 1){
    insertHead(head, data);
    return;
  }
  
  Node* temp = head;
  int cnt = 1;
  // n-1 th node tk for posi 3 go to posi 2 

  while(cnt<position-1){
    temp = temp->next;
    cnt++;
  }

  //insert at last
  if(temp->next == NULL){
    InsertTail(tail,data);
    return;
  }
  // creating a node for data
  Node* nodetoInsert = new Node(data);

  nodetoInsert->next = temp->next;
  temp->next->prev = nodetoInsert;
  temp->next= nodetoInsert; 
  nodetoInsert->prev = temp;


}
void deleteNode(int position, Node* &head){
// start node
if(position==1)
{
  Node * temp = head;
  temp->next->prev = NULL;
  head = temp->next;
  temp->next = NULL;
  // mem free
  delete temp;

}
else{
  // delete any middle or last node
  Node* curr = head; 
  Node * prev = NULL;
  int cnt = 1;

  while(cnt < position ){
    prev = curr;
    curr = curr->next;
    cnt++;  

   }
curr->prev = NULL;
prev->next =curr->next;
curr->next = NULL;
  delete curr;
  }
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print (head);
    cout<<getLenght(head)<<endl;

    insertHead(head,11 );
    print (head);
    insertHead(head,10 );
    print (head);
    insertHead(head,19 );
    print (head);
    InsertTail(tail, 99);
    print (head);

    deleteNode( 5, head);
    print (head);
    return 0;
}