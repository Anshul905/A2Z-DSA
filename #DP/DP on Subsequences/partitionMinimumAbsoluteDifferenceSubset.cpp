int minSubsetSumDifference(vector<int>& arr, int n)
{
	// int sum=0;
	// for(int i=0;i<n;i++)
	// 	sum += arr[i] ;

	// vector< vector<int> > dp(n,vector(sum+1,0));
	// for(int i=0;i<n;i++)
	// 	dp[i][0] = true;
	// if(arr[0]<=sum)
	// 	dp[0][arr[0]]=true;

	// for(int i=1;i<n;i++){
	// 	for(int j=1;j<sum+1;j++){
	// 		bool notTake = dp[i-1][j];
	// 		bool take = false;
	// 		if(j>=arr[i])
	// 			take = dp[i-1][j-arr[i]];
				
	// 		dp[i][j] = take || notTake ;
	// 	}
	// }
	// int ans = sum ; 
	// for(int i=0;i<=sum/2;i++){
	// 	if(dp[n-1][i])	
	// 		ans = min(ans,abs(sum-(2*i)));
	// }
	// return ans;


	int sum=0;
	for(int i=0;i<n;i++)
		sum += arr[i] ;

    vector<int> prev(sum+1,false);
    if(arr[0]<=sum)
        prev[arr[0]]=true;
    prev[0]=true;

    for(int i=1;i<n;i++){
        vector<int> cur(sum+1,false);
        for(int j=0;j<sum+1;j++){
            bool notTake = prev[j];
            bool take = false;
            if(j>=arr[i])
                take = prev[j-arr[i]];
                
            cur[j] = take || notTake ;
        }
        prev = cur;
    }
	int ans = sum ; 
	for(int i=0;i<=sum/2;i++){
		if(prev[i])	
			ans = min(ans,abs(sum-(2*i)));
	}
	return ans;

}


leetcode version contains negative also 
https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/


// there is a use of last row  --> Its Recusrion and memorization ??

// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 
// tabular            : n*target , m*target
// space optimization : n*target , target
