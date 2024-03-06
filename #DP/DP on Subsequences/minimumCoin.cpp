int fun( int ind, int target_sum,vector<int> &nums,vector<vector<int>> &dp){
	if(ind==0){
		if( target_sum%nums[ind]==0 ) return target_sum/nums[ind];
		return 1e9;
	}

	if(dp[ind][target_sum]!=-1)
		return dp[ind][target_sum];

	int notTake = 0 + fun(ind-1, target_sum, nums, dp);
	int take = INT_MAX;
	if(nums[ind]<=target_sum)	
		take = 1 + fun(ind, target_sum-nums[ind], nums, dp);

	return dp[ind][target_sum]=min(take,notTake);
}

int minimumElements(vector<int> &num, int x)
{
// Recursion          : >>2^(n)    , >>stack ( n )  [ O(x)]
// memoization        : n*x , n*x + >>stack ( n )  [ O(x)]

    // int n=num.size();
    // vector<vector<int>> dp(n,vector<int>(x+1,-1));
	// int ans =  fun(n-1,x,num,dp);
    // if(ans==1e9)
    //     return -1;
    // return ans;



// tabular            : n*x , n*x

    // int n=num.size();
    // vector<vector<int>> dp(n,vector<int>(x+1,0));
	
    // for(int j=0;j<x+1;j++){
    //     if(j%num[0]==0)
    //         dp[0][j]=j/num[0];
    //     else
    //         dp[0][j]=1e9;
    // }

    // for(int ind=1;ind<n;ind++){
    //     for(int j=0;j<x+1;j++){
    //         int notTake = 0 + dp[ind-1][j];
    //         int take = INT_MAX;
    //         if(num[ind]<=j)	
    //             take = 1 + dp[ind][j-num[ind]];
    //         dp[ind][j] = min(take,notTake);
    //     }
    // }
    // int ans = dp[n-1][x];
    // if(ans==1e9)
    //     return -1;
    // return ans;





// space optimization : n*x , x ( linear ) ( prev + cur )

    int n=num.size();
    vector<int> prev(x+1,0)	;
    for(int j=0;j<x+1;j++){
        if(j%num[0]==0)
            prev[j]=j/num[0];
        else
            prev[j]=1e9;
    }

    for(int ind=1;ind<n;ind++){
        vector<int> cur(x+1,0);
        for(int j=0;j<x+1;j++){
            int notTake = 0 + prev[j];
            int take = INT_MAX;
            if(num[ind]<=j)	
                take = 1 + cur[j-num[ind]];
            cur[j] = min(take,notTake);
        }
        prev=cur;
    }

    int ans = prev[x];
    if(ans==1e9)
        return -1;
    return ans;


// further space optimization : n*x , x ( linear ) ( prev  )

    // int n=num.size();
    // vector<int> prev(x+1,0)	;
    // for(int j=0;j<x+1;j++){
    //     if(j%num[0]==0)
    //         prev[j]=j/num[0];
    //     else
    //         prev[j]=1e9;
    // }

    // for(int ind=1;ind<n;ind++){
    //     for(int j=0;j<x+1;j++){
    //         int notTake = 0 + prev[j];
    //         int take = INT_MAX;
    //         if(num[ind]<=j)	
    //             take = 1 + prev[j-num[ind]];
    //         prev[j] = min(take,notTake);
    //     }
    // }

    // int ans = prev[x];
    // if(ans==1e9)
    //     return -1;
    // return ans;

}

// f(ind,x) dp[ind][x] --> ind index tak me coin_sum = x kitna minimum no. of coin leke aa sakta hai --> int  
// Recursion          : >>2^(n)    , >>stack ( n )  [ O(x)]
// memoization        : n*x , n*x + >>stack ( n )  [ O(x)]
// tabular            : n*x , n*x
// space optimization : n*x , x ( linear ) ( prev + cur )
// further space optimization : n*x , x ( linear ) ( prev  )


// Recursion          : >>2^(n)    , stack ( n ) ????
// TC : there is not only 2 path , you can still choose current one again  
// SC : coin is 1 wala , recursion space will be O(x)


// how further space optimization??
// we are storing cur in prev ( because ke us part ki jarurat nahi padegi hame to cur se usko update kar rahe hai )