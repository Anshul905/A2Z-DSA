class Solution {
public:
    int fun(int i, int j, int n, vector<vector<int>>& dp,
            vector<vector<int>>& mat) {
        if (i == n - 1)
            return mat[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = mat[i][j] + min(fun(i + 1, j, n, dp, mat),
                                          fun(i + 1, j + 1, n, dp, mat));
    }

    int minimumTotal(vector<vector<int>>& mat) {

        // dp ( memoization   m*n , m*n + stack(m-1+n-1) )

        // int n = mat.size();
        // vector< vector<int> > dp(n,vector<int>(n,-1));
        // return fun(0,0,n,dp,mat);

        // tabulation ( m*n , m*n  )

        // int n = mat.size();
        // vector< vector<int> > dp(n,vector<int>(n,-1));
        // for(int i=n-1;i>=0;i--){
        // 	for(int j=0;j<=i;j++){
        // 		if(i==n-1){
        // 			dp[i][j] = mat[i][j];
        // 		}else{
        // 			dp[i][j] = mat[i][j] + min( dp[i+1][j] , dp[i+1][j+1] );
        // 		}
        // 	}
        // }
        // return dp[0][0];

        // space optimization ( m*n , n  )

        int n = mat.size();
        vector<int> next(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> cur(n, 0);
            for (int j = 0; j <= i; j++) {
                if (i == n - 1) {
                    cur[j] = mat[i][j];
                } else {
                    cur[j] = mat[i][j] + min(next[j], next[j + 1]);
                }
            }
            next = cur;
        }
        return next[0];
    }
};





// Recursion :  2^(1+2+3+...*n) , stack ( n-1 )
// memoization :  n*n , n*n + stack ( n-1 ) 
// tabular : n*n , n*n 
// space optimization : n*n , n

// actually TC not n*n but ( n*(n+1)/2)
