class Solution {
public:
    int fun(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& mat) {
        if (n == 0 && m == 0)
            return mat[0][0];
        if (n < 0 || m < 0)
            return INT_MAX;

        if (dp[m][n] != -1)
            return dp[m][n];

        return dp[m][n] = mat[m][n] +
                          min(fun(m - 1, n, dp, mat), fun(m, n - 1, dp, mat));
    }

    int minPathSum(vector<vector<int>>& mat) {

        // dp ( memoization   m*n , m*n + stack(m-1+n-1) )

        // int m = mat.size();
        // int n = mat[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return fun(m - 1, n - 1, dp, mat);

        // tabulation ( m*n , m*n  )

        // int m = mat.size() ;
        // int n = mat[0].size() ;
        // vector< vector<int> > dp(m,vector<int>(n,-1));
        // // dp[0][0]=1;

        // for(int i=0;i<m;i++){
        // 	for(int j=0;j<n;j++){
        // 		if(i==0&&j==0) dp[i][j]=mat[0][0];
        // 		else{
        // 			int up = INT_MAX , left = INT_MAX ;
        // 			if(i-1>=0)
        // 				up = dp[i-1][j];
        // 			if(j-1>=0)
        // 				left = dp[i][j-1];
        // 			dp[i][j] = mat[i][j]+min(up,left);
        // 		}
        // 	}
        // }
        // return dp[m-1][n-1];

        // space optimization ( m*n , n  )

        int m = mat.size();
        int n = mat[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    cur[j] = mat[0][0];
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if (i - 1 >= 0)
                        up = prev[j];
                    if (j - 1 >= 0)
                        left = cur[j - 1];
                    cur[j] = mat[i][j] + min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};


// Recursion :  2^(m*n) , stack ( m-1+n-1 ) 
// memoization :  m*n , m*n + stack ( m-1+n-1 ) 
// tabular : m*n , m*n 
// space optimization : m*n , n