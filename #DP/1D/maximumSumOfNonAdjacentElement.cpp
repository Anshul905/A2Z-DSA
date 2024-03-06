#include <bits/stdc++.h> 
int fun(vector<int> &nums,int ind,vector<int> &dp){

    if(ind==0)
        return nums[ind];
    if(ind<0)
        return 0;

    if(dp[ind]!=-1)
        return dp[ind];

    int pick = nums[ind] + fun(nums,ind-2,dp);
    int notPick = 0 + fun(nums,ind-1,dp);

    return dp[ind] = max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){

    // dp ( memoization n,2*n )

    // int n = nums.size() ;
    // vector<int> dp(n,-1);
    // return fun(nums,n-1,dp);



    // tabulation ( n,n )

    // int n = nums.size() ;
    // vector<int> dp(n,0);
    // dp[0]=nums[0];
    // for(int i=1;i<=n;i++){
    //     int pick = nums[i];
    //     if(i>=2)
    //         pick += dp[i-2];
    //     int notPick = 0+dp[i-1];

    //     dp[i] = max(pick,notPick);
    // }
    // return dp[n-1];





    // space optimization ( n,1)

    int n = nums.size() ;
    int prev2 ;
    int prev = nums[0];
    for(int i=1;i<n;i++){
        int pick = nums[i];
        if(i>=2)
            pick += prev2;
        int notPick = 0+prev;

        int cur = max(pick,notPick);
        prev2 = prev ;
        prev = cur ;
    }
    return prev;

}


// pattern -> subsequence ( pick or not pick )
// recursion (2^n,stack)-> memoization (n,n+stack)-> tabular (n,n)-> space optimization (n,1) 

