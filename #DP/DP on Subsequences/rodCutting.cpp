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


int cutRod(vector<int> &value, int length_of_rod)
{
	int n = value.size();
	vector<int> weight(length_of_rod,0);
	for(int i=0;i<length_of_rod;i++)
		weight[i]=i+1;


// Recursion          : >>2^(n)    , >>stack ( n )  [ O(length_of_rod)]
// memoization        : n*length_of_rod , n*length_of_rod + >>stack ( n )  [ O(length_of_rod)]


	// vector<vector<int>> dp(n,vector<int>(length_of_rod+1,-1));
	// return fun(n-1,length_of_rod,weight,value,dp);






// tabular            : n*length_of_rod , n*length_of_rod

    // vector<vector<int>> dp(n,vector<int>(length_of_rod+1,0));
    // for(int j=0;j<length_of_rod+1;j++)
    //         dp[0][j]=(j/weight[0])*value[0];
    
    // for(int ind=1;ind<n;ind++){
    //     for(int j=0;j<length_of_rod+1;j++){
    //         int notTake = 0 + dp[ind-1][j];
    //         int take = INT_MIN;
    //         if(weight[ind]<=j)	
    //             take = value[ind] + dp[ind][j-weight[ind]];
    //         dp[ind][j] = max(take,notTake);
    //     }
    // }
    // return dp[n-1][length_of_rod];






// space optimization : n*length_of_rod , length_of_rod ( linear ) ( prev + cur )

    vector<int>prev(length_of_rod+1,0);	
    for(int j=0;j<length_of_rod+1;j++)
            prev[j]=(j/weight[0])*value[0];
 
    for(int ind=1;ind<n;ind++){
        vector<int>cur(length_of_rod+1,0);
        for(int j=0;j<length_of_rod+1;j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if(weight[ind]<=j)	
                take = value[ind] + cur[j-weight[ind]];
            cur[j] = max(take,notTake);
        }
        prev = cur;
    }
    return prev[length_of_rod];


// further space optimization : n*length_of_rod , length_of_rod ( linear ) ( prev  )

    // vector<int>prev(length_of_rod+1,0);	
    // for(int j=0;j<length_of_rod+1;j++)
    //         prev[j]=(j/weight[0])*value[0];
 
    // for(int ind=1;ind<n;ind++){
    //     for(int j=0;j<length_of_rod+1;j++){
    //         int notTake = 0 + prev[j];
    //         int take = INT_MIN;
    //         if(weight[ind]<=j)	
    //             take = value[ind] + prev[j-weight[ind]];
    //         prev[j] = max(take,notTake);
    //     }
    // }
    // return prev[length_of_rod];



}



// base condition :
// jitna ho sake le lo 


// f(ind,length_of_rod) dp[ind][length_of_rod] --> ind index tak me leng = length_of_rod me kitna maximum profit/value ho sakta hai --> int  
// Recursion          : >>2^(n)    , >>stack ( n )  [ O(length_of_rod)]
// memoization        : n*length_of_rod , n*length_of_rod + >>stack ( n )  [ O(length_of_rod)]
// tabular            : n*length_of_rod , n*length_of_rod
// space optimization : n*length_of_rod , length_of_rod ( linear ) ( prev + cur )
// further space optimization : n*length_of_rod , length_of_rod ( linear ) ( prev  )


// Recursion          : >>2^(n)    , stack ( n ) ????
// TC : there is not only 2 path , you can still choose current one again  
// SC : coin is 1 wala , recursion space will be O(length_of_rod)

// how further space optimization??
// we are storing cur in prev ( because ke us part ki jarurat nahi padegi hame to cur se usko update kar rahe hai )