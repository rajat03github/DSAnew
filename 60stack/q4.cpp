void pushatBottom(stack<int> &s, int element){
//     base case 
    if(s.empty()){
        s.push(element);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
//     recursive call 
    pushatBottom(s , element);
    
    s.push(num);
    
}



void reverseStack(stack<int> &stack) {
    // Write your code here
//     base case
    if(stack.empty () ){
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
//     recursive call 
    reverseStack(stack);
    
    pushatBottom(stack,num);
    
}