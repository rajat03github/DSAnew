#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int count, int size)
{
//     base case 
    if(count == size/2 ) //middle element
    {
        inputStack.pop();
        return ; 
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
//    recursive
    solve(inputStack , count +1 , size);
    
//     num wapas daaldo jab wps aar ha 
    inputStack.push(num);
    
    
}

void deleteMiddle(stack<int>&inputStack, int N){
	    
   // Write your code here
    int count = 0;
    solve(inputStack , count , N );
    
   
}