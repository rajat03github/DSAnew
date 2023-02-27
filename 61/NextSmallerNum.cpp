#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s ; 
    s.push(-1);
    vector<int>ans(n);
    
//     right side se chala raha hu 
    for(int i = n- 1 ; i>= 0 ; i-- ){
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();  
        }
//         ans is stack top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans ; 
}