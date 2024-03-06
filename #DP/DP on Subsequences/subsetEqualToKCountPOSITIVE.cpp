int mod = (int)(1e9+7);

// when arr[i]>0 is always positive 
int funOnlyPositive(int i,int target,vector<int>&arr,vector< vector<int> > &dp){
    if(target==0)
        return 1;			
    if(i==0){
        if(arr[0]==target)
			return 1;
		return 0;
	}

    if(dp[i][target]!=-1)
        return dp[i][target];

    int notTake = funOnlyPositive(i-1,target,arr,dp);
    int take = 0;
    if(target>=arr[i])
        take = funOnlyPositive(i-1,target-arr[i],arr,dp);

    return  dp[i][target] = (take+notTake)%mod;
}




int findWays(vector<int>& arr, int target)
{

	// int n = arr.size();
    // vector< vector<int> > dp(n,vector(target+1,-1));
    // return funOnlyPositive(n-1,target,arr,dp);


    // sort(arr.begin(),arr.end(),greater<int>()); // to handle zeros 
    // int n=arr.size();
    // vector<vector<int>> dp(n,vector<int>(target+1,0));
    // dp[0][0]=1;
    // if(arr[0]<=target)
    //     dp[0][arr[0]]=1;

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




    sort(arr.begin(),arr.end(),greater<int>()); // to handle zeros 
	int n = arr.size();
    vector<int> prev(target+1,0);
    if(arr[0]<=target)
        prev[arr[0]]=1;
    prev[0]=1;

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





// if you sort array in descending order at first before other things are done
// that will work for array containing 0 also 

// funNonNegative --> function when arr[i] >= 0
// funOnlyPositive --> function when arr[i] > 0

// tabular , space optimization ( for zeros also ) --> use sorting to handle zeros 
// tabular , space optimization are written for positive number here, so you want to use for zeros also --> use sort ( decending ) 

// sort(arr.begin(),arr.end(),greater<int>());
// this is for cases like {0,0,1} and k=1 , ans should be 4 but it will give answer 1 so sort it in descending order so all the zeros will got to right side 



// f(i,target) dp[i][target] --> array me ith index tak target ka count kitna hai --> bool  
// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 
// tabular            : n*target , m*target
// space optimization : n*target , target
