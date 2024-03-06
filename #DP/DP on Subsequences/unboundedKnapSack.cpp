#include <bits/stdc++.h> 
int fun( int ind, int capacity,vector<int> weight, vector<int> value,vector<vector<int>> &dp){
	if(ind==0){
        return (capacity/weight[ind])*value[ind];
	}
	if(dp[ind][capacity]!=-1)
		return dp[ind][capacity];
	int notTake = 0 + fun(ind-1, capacity, weight, value, dp);
	int take = INT_MIN;
	if(weight[ind]<=capacity)	
		take = value[ind] + fun(ind, capacity-weight[ind], weight, value, dp);

	return dp[ind][capacity]=max(take,notTake);
}

int unboundedKnapsack(int n, int target, vector<int> &value, vector<int> &weight){

// Recursion          : >>2^(n)    , >>stack ( n )  [ O(target)]
// memoization        : n*target , n*target + >>stack ( n )  [ O(target)]

	// vector<vector<int>> dp(n,vector<int>(target+1,-1));
	// return fun(n-1,target,weight,value,dp);




// tabular            : n*target , n*target


    // vector<vector<int>> dp(n,vector<int>(target+1,0));
    // for(int j=0;j<target+1;j++)
    //         dp[0][j]=(j/weight[0])*value[0];
    
    // for(int ind=1;ind<n;ind++){
    //     for(int j=0;j<target+1;j++){
    //         int notTake = 0 + dp[ind-1][j];
    //         int take = INT_MIN;
    //         if(weight[ind]<=j)	
    //             take = value[ind] + dp[ind][j-weight[ind]];
    //         dp[ind][j] = max(take,notTake);
    //     }
    // }
    // return dp[n-1][target];





// space optimization : n*target , target ( linear ) ( prev + cur )


    vector<int>prev(target+1,0);
	
    for(int j=0;j<target+1;j++)
            prev[j]=(j/weight[0])*value[0];
 
    for(int ind=1;ind<n;ind++){
        vector<int>cur(target+1,0);
        for(int j=0;j<target+1;j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if(weight[ind]<=j)	
                take = value[ind] + cur[j-weight[ind]];
            cur[j] = max(take,notTake);
        }
        prev = cur;
    }
    return prev[target];


// space optimization : n*target , target ( linear ) ( prev  )


    // vector<int>prev(target+1,0);
	
    // for(int j=0;j<target+1;j++)
    //         prev[j]=(j/weight[0])*value[0];
 
    // for(int ind=1;ind<n;ind++){
    //     for(int j=0;j<target+1;j++){
    //         int notTake = 0 + prev[j];
    //         int take = INT_MIN;
    //         if(weight[ind]<=j)	
    //             take = value[ind] + prev[j-weight[ind]];
    //         prev[j] = max(take,notTake);
    //     }
    // }
    // return prev[target];




}


// base condition :
// jitna ho sake le lo 


// f(ind,target) dp[ind][target] --> ind index tak me weight = target me kitna maximum profit/value ho sakta hai --> int  
// Recursion          : >>2^(n)    , >>stack ( n )  [ O(target)]
// memoization        : n*target , n*target + >>stack ( n )  [ O(target)]
// tabular            : n*target , n*target
// space optimization : n*target , target ( linear ) ( prev + cur )
// further space optimization : n*target , target ( linear ) ( prev  )


// Recursion          : >>2^(n)    , stack ( n ) ????
// TC : there is not only 2 path , you can still choose current one again  
// SC : coin is 1 wala , recursion space will be O(target)

// how further space optimization??
// we are storing cur in prev ( because ke us part ki jarurat nahi padegi hame to cur se usko update kar rahe hai )