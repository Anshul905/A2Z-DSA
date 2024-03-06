#include <bits/stdc++.h> 
int fun(int m, int n, vector<vector<int>>& dp,vector<vector<int>> &mat) {
	if ( n<0 || n>=mat[0].size())
		return INT_MIN;
	if (m==0)
        return  mat[m][n];

	if (dp[m][n] != -1)
		return dp[m][n];
    
    int u = fun(m-1,n,dp,mat);
    int ld = fun(m-1,n-1,dp,mat);
    int rd = fun(m-1,n+1,dp,mat);

	return dp[m][n] = mat[m][n] + max( u,max(ld,rd) ) ;
}

int getMaxPathSum(vector<vector<int>> &mat)
{

    // dp ( memoization   n ( for all elements of last row ) *(m*n) , m*n + stack(n-1) )

    // int m = mat.size() ;
    // int n = mat[0].size() ;
    // int ans = INT_MIN ;
    // for(int j=0;j<n;j++){
    // 	vector< vector<int> > dp(m,vector<int>(n,-1));
    //     int cur = fun(m-1,j,dp,mat);
    //     ans = max(ans,cur);
    //     dp.clear();
    // }
    // return ans;


    // tabulation ( m*n + n , m*n  )

    // int m = mat.size() ;
    // int n = mat[0].size() ;
    // vector< vector<int> > dp(m,vector<int>(n,0));

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         if(i==0)dp[0][j] = mat[0][j];
    //         else{
    //             int u =  dp[i-1][j];
    //             int ld=INT_MIN , rd = INT_MIN;
    //             if(j-1>=0)ld = dp[i-1][j-1];
    //             if(j+1<=n-1)rd = dp[i-1][j+1];
    //             dp[i][j] = mat[i][j] + max( u,max(ld,rd) );
    //         }
    //     }            
    // }
    // int ans=INT_MIN;
    // for(int j=0;j<n;j++)
    //     ans= max(ans,dp[m-1][j]);
    // return ans;


    // space optimization( m*n + n , n  )

    int m = mat.size() ;
    int n = mat[0].size() ;

    vector<int> prev(n,0);

    for(int i=0;i<m;i++){
        vector<int> cur(n,0);
        for(int j=0;j<n;j++){
            if(i==0) cur[j]=mat[i][j];
            else{
                int u =  prev[j];
                int ld=INT_MIN , rd = INT_MIN;
                if(j-1>=0)ld = prev[j-1];
                if(j+1<=n-1)rd = prev[j+1];
                cur[j] = mat[i][j] + max( u,max(ld,rd) );
            }
        }
        prev = cur ;
    }

    int ans=INT_MIN;
    for(int j=0;j<n;j++)
        ans= max(ans,prev[j]);
    return ans;

}

// Recursion :  n ( for all elements of last row ) * (3^m) , stack ( m-1 ) [ maximum n in the stack and 3 path for each ]
// memoization :  n ( for all elements of last row ) * (m*n*3) , m*n + stack ( m-1 ) 
// tabular : m*n + o(n) , m*n 
// space optimization : m*n , n



// time complexity of recursion ? i did not understand 
// why not n(elements)* 3^(m*n)?
// 3^(m*n) for one element 

