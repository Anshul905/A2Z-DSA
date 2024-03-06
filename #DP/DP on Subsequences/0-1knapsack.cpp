#include <bits/stdc++.h> 
int fun( int ind, int capacity,vector<int> weight, vector<int> value,vector<vector<int>> &dp){
	if(ind==0){
		if( weight[ind]<=capacity ) return value[0];
		return 0;
	}
	if(dp[ind][capacity]!=-1)
		return dp[ind][capacity];
	int notTake = 0 + fun(ind-1, capacity, weight, value, dp);
	int take = INT_MIN;
	if(weight[ind]<=capacity)	
		take = value[ind] + fun(ind-1, capacity-weight[ind], weight, value, dp);

	return dp[ind][capacity]=max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*capacity , n*capacity + stack ( n ) 

	// vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
	// return fun(n-1,capacity,weight,value,dp);





// tabular   : n*capacity , n*capacity

		// vector<vector<int>> dp(n,vector<int>(capacity+1,0));
		// for(int j=0;j<capacity+1;j++){
		// 	if(j>=weight[0])
		// 		dp[0][j]=value[0];
		// }
		// for(int ind=1;ind<n;ind++){
		// 	for(int j=0;j<capacity+1;j++){
		// 		int notTake = 0 + dp[ind-1][j];
		// 		int take = INT_MIN;
		// 		if(weight[ind]<=j)	
		// 			take = value[ind] + dp[ind-1][j-weight[ind]];
		// 		dp[ind][j] = max(take,notTake);
		// 	}
		// }
		// return dp[n-1][capacity];




// space optimization : n*capacity , capacity ( linear )

		// vector<int> prev(capacity+1,0);
		// for(int j=0;j<capacity+1;j++){
		// 	if(j>=weight[0])
		// 		prev[j]=value[0];
		// }
		// for(int ind=1;ind<n;ind++){
		// 	vector<int> cur(capacity+1,0);
		// 	for(int j=0;j<capacity+1;j++){
		// 		int notTake = 0 + prev[j];
		// 		int take = INT_MIN;
		// 		if(weight[ind]<=j)	
		// 			take = value[ind] + prev[j-weight[ind]];
		// 		cur[j] = max(take,notTake);
		// 	}
		// 	prev = cur;
		// }
		// return prev[capacity];




// Further space optimization : n*capacity , capacity ( linear ) ( prev )

		vector<int> prev(capacity+1,0);
		for(int j=0;j<capacity+1;j++){
			if(j>=weight[0])
				prev[j]=value[0];
		}
		for(int ind=1;ind<n;ind++){
			for(int j=capacity;j>=0;j--){
				int notTake = 0 + prev[j];
				int take = INT_MIN;
				if(weight[ind]<=j)	
					take = value[ind] + prev[j-weight[ind]];
				prev[j] = max(take,notTake);
			}
		}
		return prev[capacity];


}











// f(ind,capacity) dp[ind][capacity] --> ind index tak weight=capactiy me kitna maximum profit/value you can earn --> int  
// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*capacity , n*capacity + stack ( n ) 
// tabular            : n*capacity , n*capacity
// space optimization : n*capacity , capacity ( linear ) ( prev + cur )
// Further space optimization : n*capacity , capacity ( linear ) ( prev )

// Further space optimization????
// we dont need right part of the prev so we will start storing new values in that part , for that we need to traverse from right ( because  for any cell we want prevs value before that index so it wont get override , while traversing right to left we are overriding the value which dont need in the left part )


