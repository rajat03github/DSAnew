// aggressive cows 

// ISPOSSIBLE

bool Possible(vector<int>&stalls, int  k , int  mid )
{
    int cowCount = 1 ; 
    int currentPos = stalls[0];

    for(int i = 0; i < stalls.size(); i++){
        if(stalls[i] - currentPos >= mid ){
            cowCount++;
            if(cowCount == k ){
                return true;
            }
            currentPos = stalls[i];
        }
    }
    return false ;
}

// sorting
sort(stalls.begin(), stalls.end()); 

int s = 0;
int maxi = -1;
for( int i = 0; i< stalls.size(); i++){
    maxi = max(maxi, stalls[i]);
}
int e = maxi;

int ans = -1;
int mid = s+ ( e- s)/ 2;

while (s<=e)
{
    /* code */
    if(Possible(stalls, k , mid ))
    {
        ans = mid;
        s = mid +1 ; 
    }
    else 
    {
        e = mid - 1;

    }
    mid = s+ ( e- s )/2 ;
}
return ans ;