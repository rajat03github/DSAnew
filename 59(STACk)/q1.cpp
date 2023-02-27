#include <iostream>
#include <stack>
using namespace std;

// without stl implementaion 
class Stack {

    //properties 
    public:
        int *arr; 
        int top;
        int size;
    //behaviour

    Stack(int size) {
        this->size = size;
        arr = new int[size]; 
        top = -1 ; 
    }
    // stack functions 

    void push( int element ){

        // at least one empty 
        if(size - top > 1){
            top ++;
            arr[top] = element;
        }
        else{
            cout<<"stack overflow "<<endl;
        }

    }
    void pop(){
        // atleast one prsent
        if(top >= 0) { 
            top --;
        }
        else {
            cout<<"stack underflow" ;

        }

    }
    int peek (){
        if(top >= 0 && top < size)
             return arr[top];
        else{
            cout<<"stack is empty ";
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1 )
        {
            return true ;
        }
        else{
            return false ;
        }
    }

};


int main()
{

    Stack st(5);

    st.push(22);
    st.push(44);
    st.push(44);
    st.push(96);
    st.push(22);


    cout<<st.peek() <<endl;

    st.pop();
    cout<<st.peek() <<endl;

    st.pop();
    cout<<st.peek() <<endl;

    st.pop();
    cout<<st.peek() <<endl;

    if(st.isEmpty()){
        cout<<"stack is empty "<<endl;
    }
    else{
        cout<<"not empty "<<endl;
    }
        



/*
    // stack using stl
    stack<int> s;

    // push
    s.push(2);
    s.push(4);

    // pop
    s.pop();

    cout << "Printing element on top" << s.top();

    //    is emprty?
    if (s.empty())
    {
        cout << "stack is empty";
    }
    else
    {
        cout << "not empty ";
    }

    cout<<"size of stack is "<<s.size()<<endl;
*/
    return 0;
}