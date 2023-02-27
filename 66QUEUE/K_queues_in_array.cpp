#include<iostream>
using namespace std;

class kQueue{

    public:
        int n;
        int k;
        int *front ; 
        int * rear ;
        int *arr ; 
        int freespot ; 
        int * next ; 

    public:
        kQueue(int n , int k ){
            this->n = n  ;
            this->k = k; 
            front = new int[k]; 
            rear = new int[k];
            for(int i = 0; i < k ; i ++ ){
                front[i] = -1;
                rear[i] = -1; 

            }
            next = new int[n];
            for(int i = 0 ; i < n ; i ++ )
            {
                next[i] = i+1;
            }
            next[n-1] = -1;

            arr = new int[n]; 
            freespot = 0;
        }

        void enque(int data , int qn){

            // overflow check
            if(freespot == -1 ){
                cout<< "no empty space is available "<<endl;
                return;
            }

            // find first free index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // check whether first element 
            // here qn-1 is because 0th index is used
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                // link element present index to the new index
                next[ rear [qn-1]  ] = index ; 
            }

            // update next 
            next[index] = -1;

            // update rear 

            rear [qn - 1] = index; 

            // push 
            arr[index] = data ;


        }


        // POP
        int deque( int qn ){
            // check underflow 
            if(front [ qn -  1] == -1 ) // is empty  
            {
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            //find index to pop 
            int index = front [qn - 1 ];

            // front ko aage badhao 
            front [ qn - 1 ] = next [ index ];

            // free sloot ko manage kro
            next [ index ] = freespot ;
            freespot = index ; //freespot - pahla possible freespot

            return arr[index] ; 
        }

}; 

int main(){

    kQueue q(10 , 3); //n,k
    q.enque(10 , 1);
    q.enque(15 , 2);
    q.enque(20 , 1);
    q.enque(25 , 2);

    cout<<q.deque(1) <<endl;
    cout<<q.deque(2) <<endl;
    cout<<q.deque(1) <<endl;
    cout<<q.deque(2) <<endl;

    return 0;
} 