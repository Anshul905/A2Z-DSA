#include <bits/stdc++.h> 
int fun(int n,vector<int> &dp, vector<int>&heights){
    if( n==0 )
        return 0 ;

    if(dp[n]!=-1)
        return dp[n];
        
    int l = fun(n-1,dp,heights)+abs(heights[n]-heights[n-1]) ;
    int r=INT_MAX;
    if(n>=2){
       r = fun(n-2,dp,heights)+abs(heights[n]-heights[n-2]) ;
    }

    return  dp[n] = min(l,r);
}

int frogJump(int n, vector<int> &heights)
{
    // dp ( memoization n,2*n )

    // vector<int> dp(n,-1);
    // return fun(n-1,dp,heights);




    // tabulation ( n,n )

    // vector<int> dp(n,0);
    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int l = dp[i-1]+abs(heights[i]-heights[i-1]);
    //     int r = INT_MAX ;
    //     if(i>=2)
    //         r = dp[i-2]+abs(heights[i]-heights[i-2]);

    //     dp[i] = min(l,r);
    // }
    // return dp[n-1];




    // space optimization ( n,1)
    
    int prev2 = 0 ;
    int prev = 0 ;
    for(int i=1;i<n;i++){
        int l = prev+abs(heights[i]-heights[i-1]);
        int r = INT_MAX ;
        if(i>=2)
            r = prev2+abs(heights[i]-heights[i-2]);
        
        int cur = min(l,r) ;
        prev2 = prev ;
        prev = cur ;
    }
    return prev;

}


// recursion (2^n,stack)-> memoization (n,n+stack)-> tabular (n,n)-> space optimization (n,1)

// dont check if(n<0) --> because that function will return INT_MAX but heights[negative] will create problem  
// instead check if n>=2 then solve else INT_MAX  


