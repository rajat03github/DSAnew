#include<vector>
class Solution 
{

    private:
    
    bool knows(vector<vector<int> >& M, int a , int b , int n )
    {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s ;
        // step 1 push all elements in stack
         for(int i = 0 ; i < n ; i++ )
         {
             s.push(i);
         }
        //  step 2 
        while(s.size() > 1)
        {
         int a = s.top();
         s.pop();
         
         int b = s.top();
         s.pop();
         
         if(knows(M,a,b,n)){
             s.push(b);
         }
         else
         {
             s.push(a);
         }
         
        }
        
        int celeb = s.top();
        // step 3, single elementcan be celeb so verify 
        
        bool rowCheck = false ;
        
        int zerocount = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(M[celeb][i] == 0 ){
                zerocount ++ ;
            }
            
        }
        // check for all 0s
        if(zerocount == n )
        {
            rowCheck = true;
        }
        // check colm
        bool colCheck = false ;
        int onecount = 0;
        
         for(int i = 0 ; i < n ; i++)
        {
            if(M[i][celeb] == 1 ){
                onecount ++ ;
            }
            
        }
        // check without diagonal
        if(onecount == n -1 )
        {
            colCheck = true ; 
        }
        
        if(rowCheck == true && colCheck == true ){
            return celeb ;
        }
        else
        {
            return -1;
        }
        
    }
};