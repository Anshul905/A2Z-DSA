int mod = (int)(1e9+7);

// when arr[i]>=0 is non negative
int funNonNegative(int i,int target,vector<int>&arr,vector< vector<int> > &dp){
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

    int notTake = funNonNegative(i-1,target,arr,dp);
    int take = 0;
    if(target>=arr[i])
        take = funNonNegative(i-1,target-arr[i],arr,dp);

    return  dp[i][target] = (take+notTake)%mod;
}


int findWays(vector<int>& arr, int target)
{

	// int n = arr.size();
    // vector< vector<int> > dp(n,vector(target+1,-1));
    // return funNonNegative(n-1,target,arr,dp);





	// int n = arr.size();
    // vector<vector<int>> dp(n,vector<int>(target+1,0));
    
    // if( arr[0]==0 ) dp[0][0]=2; 
    // else dp[0][0]=1;
    // if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;

    // for(int i=1;i<n;i++){
    //     for(int j=0;j<target+1;j++){
    //         int notTake = dp[i-1][j];
    //         int take = 0;
    //         if(j>=arr[i])
    //             take = dp[i-1][j-arr[i]];
    //         dp[i][j] = (take+notTake)%mod;
    //     }
    // }
    // return dp[n-1][target];




	int n = arr.size();
    vector<int> prev(target+1,0);
    
    if( arr[0]==0 ) prev[0]=2; 
    else prev[0]=1;
    if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;


    for(int i=1;i<n;i++){
        vector<int> cur(target+1,0);
        for(int j=0;j<target+1;j++){
            int notTake = prev[j];
            int take = 0;
            if(j>=arr[i])
                take = prev[j-arr[i]];
                
            cur[j] = (take+notTake)%mod ;
        }
        prev = cur;
    }
    return prev[target];
}



// base condition ( when i==0 )
// sum  a[0]
// 0    0      --> 2 ( take , not take) 
// 0    not 0  --> 1 ( not take)
// equals      --> 1 ( take)
// others      --> 0


// recusrsion/memoization 
// if(i==0){
//     if(sum==0 && arr[0]==0) return 2;
//     if(sum==0 && arr[0]!=0) return 1;
//     if(sum==arr[0])return 1;
//     return 0;
//  }


// tabular
// if( arr[0]==0 ) dp[0][0]=2;
// else dp[0][0]=1;
// if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;

// OR

// if(arr[0]<=target) dp[0][arr[0]]=1; 
// if( arr[0]==0 ) dp[0][0]=2; 
// else dp[0][0]=1;



// space optimization
// if( arr[0]==0 ) prev[0]=2; 
// else prev[0]=1;
// if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;

// OR

// if(arr[0]<=target) prev[arr[0]]=1;
// if( arr[0]==0 ) prev[0]=2; 
// else prev[0]=1;



// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 
// tabular            : n*target , m*target
// space optimization : n*target , target
