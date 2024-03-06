int fun(int m, int n, vector<vector<int>>& dp) {
	if (n == 0 && m == 0)
		return 1;
	if (n < 0 || m < 0)
		return 0;

	if (dp[m][n] != -1)
		return dp[m][n];

	return dp[m][n] = fun(m - 1, n, dp) + fun(m, n - 1, dp);
}

int uniquePaths(int m, int n) {
	// dp ( memoization   m*n , m*n + stack(m-1+n-1) )

	// vector< vector<int> > dp(m,vector<int>(n,-1));
	// return fun(m-1,n-1,dp);

	// tabulation ( m*n , m*n  )

	// vector< vector<int> > dp(m,vector<int>(n,0));
	// for(int i=0;i<m;i++){
	// 	for (int j=0; j < n; j++) {
	// 		if(i==0 && j==0) dp[i][j]=1;
	// 		else{
	// 			int up = 0 , left = 0 ;
	// 			if(i>0) up = dp[i-1][j] ;
	// 			if(j>0) left = dp[i][j-1];
	// 			dp[i][j] = up + left ;
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1];

	// space optimization ( m*n , n  )

	vector<int> prev(n, 0);
	for (int i = 0; i < m; i++) {
		vector<int> cur(n, 0);
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0)
				cur[j] = 1;
			else {
				int up = 0, left = 0;
				if (i > 0)
					up = prev[j];
				if (j > 0)
					left = cur[j - 1];
				cur[j] = up + left;
			}
		}
		prev = cur;
	}
	return prev[n - 1];
}


// Recursion :  2^(m*n) , stack ( m-1+n-1 ) 
// memoization :  m*n , m*n + stack ( m-1+n-1 ) 
// tabular : m*n , m*n 
// space optimization : m*n , n


// if there is a prev row and prev columns , we can space optimize it 