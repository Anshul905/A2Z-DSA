int fun(int n, int k, vector<int> &dp, vector<int> &heights){

    if(n==0)
        return 0;

    if(dp[n]!=-1)
        return dp[n];

    int mini = INT_MAX ;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            mini = min( mini , fun(n-i,k,dp,heights)+abs(heights[n]-heights[n-i]) );   
        }
    }
    return  dp[n] = mini ;
}

int minimizeCost(int n, int k, vector<int> &heights){
    
    // dp ( memoization n,2*n )

    // vector<int> dp(n,-1);
    // return fun(n-1,k,dp,heights);




    // tabulation ( n,n )

    // vector<int> dp(n,0);
    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int mini = INT_MAX;
    //     for(int j=1;j<=k;j++){
    //         if(i-j>=0)
    //             mini = min(mini,dp[i-j]+abs(heights[i]-heights[i-j]));
    //     }
    //     dp[i] = mini;
    // }
    // return dp[n-1];




    // space optimization ( n,k)
    
    vector<int> prevs(k,0);
    int cur = 0;
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0)
                mini = min(mini,prevs[k-j]+abs(heights[i]-heights[i-j]));
        }
        cur = mini ;
        prevs.erase( prevs.begin() );
        prevs.push_back(cur);
    }
    return cur;

}

// recursion (k^n,stack)-> memoization (n*k,n+stack)-> tabular (n*k,n)-> space optimization (n,k) worst case (n,n)

// dont check if(n<0) --> because that function will return INT_MAX but heights[negative] will create problem  
// instead check if n>=2 then solve else INT_MAX  
