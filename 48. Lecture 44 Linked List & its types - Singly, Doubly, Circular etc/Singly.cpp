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
  if(this->next != NULL){
    delete next;
    this->next = NULL;
  }
  cout<<"mem is free for node with data "<< value <<endl;
}

};

void insertHead(Node* &head, int data){

  // new node create
  Node*temp = new Node(data);
  temp->next = head;
  head = temp ;
  
}

void InsertTail(Node* &tail , int data){
// new node create
Node*temp = new Node(data);
tail->next = temp;
tail = temp;

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
  }
  // creating a node for data
  Node* nodetoInsert = new Node(data);
  nodetoInsert->next = temp->next;
  temp->next = nodetoInsert;
}

void deleteNode(int position, Node* &head){
// start node
if(position==1)
{
  Node * temp = head;
  head = head->next;
  // mem free
  temp->next = NULL;
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
  prev->next= curr->next;
  curr->next = NULL;
  delete curr;
  }
}

void print (Node* &head )
{
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" "<<endl;
    temp = temp->next;
  }
  cout<<endl;
}

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
            cout<<"present on element "<<temp->data << endl;
               return true ; 
            // return 1;     

        }
        visited[temp] = true; 
        temp = temp->next;
    }

    return false;
}


// FLOYD ALGORITHM 
 Node * floydDetectLoop( Node * head ){
  if(head == NULL ){
    return NULL; 
  }
  Node* slow = head; 
  Node * fast = head; 

  while(slow != NULL && fast != NULL){

    fast = fast -> next ;
    if(fast != NULL ){
      fast = fast -> next;
    }
    slow = slow -> next ; 

    if(slow == fast ){
      // loop present 
      cout<<"Cyclic node Present at "<<slow->data<<endl;
      return slow; 
    }

  }
  
  return NULL ; 
}

Node *  getStartingNode(Node * head)
{
  if ( head == NULL ){
    return NULL ; 
  }

  Node* intersection = floydDetectLoop(head);
  Node * slow = head; 

  while(slow != intersection){
    slow = slow->next;
    intersection = intersection->next;
  }

  return slow ;

}

void removeLoop (Node * head ){
  if(head == NULL ){
    return ; 
  }
  Node * startOfLoop = getStartingNode(head ); 
  Node * temp = startOfLoop;
  while (temp->next != startOfLoop) 
  {
    /* code */
    temp = temp->next ; 
  }
  temp->next = NULL ;
  
}

int main(){
        Node * node1 = new Node(10);
        cout<< node1->data <<endl;
        cout<<node1->next<<endl;

        // head pointer to new node1
        Node* head = node1;
        // tail pointer
        Node* tail = node1;

  print(head);
        insertHead(head, 12);
  print(head);
        insertHead(head, 15);
  print(head);
        InsertTail(tail, 22);
  print(head);
        insertPosi(head, 3 , 26 ,tail);
  print(head);

  tail->next = head->next ;

  cout<<"Head "<<head->data<<endl;
  cout<<"tail "<<tail->data<<endl;

  if(floydDetectLoop(head) != NULL){
    cout<<"CYCLE present "<<endl;

  }
  else{
    cout<<"CYCLE not present "<<endl; 
  }

  Node * loop = getStartingNode(head);
    cout<<"loop start at "<< loop->data <<endl ; 

  // removing loop 
  removeLoop(head);
  print (head);

// checking again 
  if(floydDetectLoop(head) != NULL){
    cout<<"CYCLE present "<<endl;

  }
  else{
    cout<<"CYCLE not present "<<endl; 
  }
  /*
  deleteNode(4, head);
  print(head);
*/
  return 0;
}