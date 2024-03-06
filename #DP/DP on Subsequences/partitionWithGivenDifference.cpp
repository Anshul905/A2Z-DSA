#include <bits/stdc++.h> 
int mod=  1e9+7;
int fun(int i,int target,vector<int>&arr,vector< vector<int> > &dp){
    if(i==0){
        if(target==0 && arr[0]==0)
            return 2; 
        if(target==0 && arr[0]!=0 )
			return 1;
        if( arr[0]==target )
			return 1;
		return 0;
	}

    if(dp[i][target]!=-1)
        return dp[i][target];

    int notTake = fun(i-1,target,arr,dp);
    int take = 0;
    if(target>=arr[i])
        take = fun(i-1,target-arr[i],arr,dp);

    return  dp[i][target] = (take+notTake)%mod;
}


int countPartitions(int n, int d, vector<int> &arr) {

// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 


    // int sum=0;
    // for(int i=0;i<n;i++){
    //     sum += arr[i];
    // }
    // sum = sum-d;
    // if(sum%2)
    //     return 0;
    // else if(sum>=0){
    //     int newTarget = sum/2;
	// 	vector< vector<int> > dp(n,vector(newTarget+1,-1));
	// 	return fun(n-1,newTarget,arr,dp);
    // }




// tabular            : n*target , m*target


    // int sum=0;
    // for(int i=0;i<n;i++){
    //     sum += arr[i];
    // }
    // sum = sum-d;
    // if(sum%2)
    //     return 0;
    // else if(sum>=0){
    //     int newTarget = sum/2;


    //     vector<vector<int>> dp(n,vector<int>(newTarget+1,0));
    //     if(arr[0]<=newTarget)
    //         dp[0][arr[0]]=1;
    //     if(arr[0]==0)
    //         dp[0][0]=2;
    //     else
    //         dp[0][0]=1;
        

    //     for(int i=1;i<n;i++){
    //         for(int j=0;j<newTarget+1;j++){
    //             int notTake = dp[i-1][j];
    //             int take = 0;
    //             if(j>=arr[i])
    //                 take = dp[i-1][j-arr[i]];
    //             dp[i][j] = (take+notTake)%mod;
    //         }
    //     }
    //     return dp[n-1][newTarget];
    // }




// space optimization : n*target , target


    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    sum = sum-d;
    if(sum<0 || sum%2)
        return 0;
    else{
        int newTarget = sum/2;

        int n = arr.size();
        vector<int> prev(newTarget+1,0);
        if(arr[0]<=newTarget)
            prev[arr[0]]=1;
        if(arr[0]==0)
            prev[0]=2;
        else
            prev[0]=1;

        for(int i=1;i<n;i++){
            vector<int> cur(newTarget+1,0);
            for(int j=0;j<newTarget+1;j++){
                int notTake = prev[j];
                int take = 0;
                if(j>=arr[i])
                    take = prev[j-arr[i]];
                    
                cur[j] = (take+notTake)%mod ;
            }
            prev = cur;
        }
        return prev[newTarget];
    
    }


}



// similar to subset equal to K count 

// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 
// tabular            : n*target , m*target
// space optimization : n*target , target



