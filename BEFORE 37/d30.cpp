// DOUBLE POINTERS

#include<iostream>
using namespace std;

void update(int **p){
    // p = p+1;
    // kuch change hpoga  = No ( only in update but not in main)
    // *p = *p +1 ; 
    // kuch change hpoga = YES 
    **p = **p +1 ; 
    // kuch change hpoga = YES ( value of i changed in main )
}



int main()
{
    int i = 6;
    int* p = &i;
    int** p2 = &p;

    cout<<"Sab sahi chal rha hai "<<endl;

// Access method for int i value
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

//Access method for int*p value that is address
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;

//Access method for int**p value that is address
    cout<<&p<<endl;
    cout<<p2<<endl;



// FOR FUNCTION 
    cout<<"BEFORe"<<endl;
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<p2<<endl;
    // pass by value
    update(p2);
    cout<<"after "<<endl;
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<p2<<endl;
    cout<<endl;

    // MCQ QUESTION 

    // int first = 8;
    // int second = 18; 
    // int *ptr = &second;s
    // *ptr = 9;
    // cout<<first<<" "<<second<<endl;


    // int first = 8;
    // int *pq =&first; 
    // int *q = pq;
    // (*q)++ ;
    // cout<<first<<endl;

    // int first = 8;
    // int *pq =&first; 
    // // post incremenet 
    // cout<<(*pq)++<<endl;

    // cout<<first<<endl;

    // int *pn = 0;
    // int first = 110;
    // // wrong syntax because intialised 0
    // *pn = first;
    // // right syntax
    // pn = &first;
    // cout<<*pn<<endl;
    

    // float f = 12.5;
    // float pnew = 21.5;
    // float *ptr = &f;
    // (*ptr)++;
    // *ptr = pnew;
    // cout<< *ptr <<" "<< pnew<< endl;

    int arr[5];
    int *ptr;
    cout<< sizeof(arr )<< " "<<sizeof(ptr)<<endl;


    // arr[2] = *(arr + 2)

    char ch = 'a';
    char *ptr2 = &ch ; 
    ch++;
    cout<<*ptr2<<endl;
    
    // char abc[] ="avcd";
    // char *ptr3 = &abc[0];
    // cout<<ptr3<<endl;
    
    char abc[] ="avcd";
    char *ptr3 = &abc[0];
    ptr3++;
    cout<<ptr3<<endl;


    int first = 110;
    int *ptr4 =&first;
    int **q2 = &ptr4;
    // post increment thrfore 110 + 9
    int second = (**q2)++  + 9 ;
    cout<<first<< " "<< second<< endl;

    // IMPRT QUES

    int a = 100;
    int *n = &a ; 
    int **o = &n;
    int b = ++(**o);
    int *r = *o; 
    ++(*r);
    cout<<a<<" "<<b<<endl;


    return 0;
}