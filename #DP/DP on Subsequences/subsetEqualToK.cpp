#include <bits/stdc++.h> 
bool fun(int i,int target,vector<int>&arr,vector< vector<int> > &dp){

if(target==0)
    return true;
if(i==0)
    return (arr[0]==target);

if(dp[i][target]!=-1)
    return dp[i][target];

bool notTake = fun(i-1,target,arr,dp);
bool take = false;
if(target>=arr[i])
    take = fun(i-1,target-arr[i],arr,dp);

return  dp[i][target] = (take || notTake) ;
}

bool subsetSumToK(int n, int target, vector<int> &arr) {


// vector< vector<int> > dp(n,vector(k+1,-1));
// return fun(n-1,target,arr,dp);



// vector<vector<bool>> dp(n,vector(target+1,false));
// for(int i=0;i<n;i++)
//     dp[i][0] = true;
// if(arr[0]<=target)
//     dp[0][arr[0]]=true;



// for(int i=1;i<n;i++){
//     for(int j=1;j<target+1;j++){
//         bool notTake = dp[i-1][j];
//         bool take = false;
//         if(j>=arr[i])
//             take = dp[i-1][j-arr[i]];
            
//         dp[i][j] = take || notTake ;
//     }
// }
// return dp[n-1][target];




vector<int> prev(target+1,false);
if(arr[0]<=target)
    prev[arr[0]]=true;
prev[0]=true;

for(int i=1;i<n;i++){
    vector<int> cur(target+1,false);
    for(int j=0;j<target+1;j++){
        bool notTake = prev[j];
        bool take = false;
        if(j>=arr[i])
            take = prev[j-arr[i]];
            
        cur[j] = take || notTake ;
    }
    prev = cur;
}
return prev[target];

}


// f(i,target) dp[i][target] --> i index tak target hai yahi --> bool  

// dont make bool true , if it is bool , wont be able to distinguish between answer , ( false , true ) afre possible answer ans if you pass false in function , it will consider it as answer and answer ill be wrong , so keep it apart from (
//     0,1) so pass -1 

// f(i,target) dp[i][target] --> i index tak target hai ya nahi --> bool  
// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 
// tabular            : n*target , m*target
// space optimization : n*target , target
