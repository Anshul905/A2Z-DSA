class Solution {
public:
    int fun(int ind1, int ind2, string text1, string text2,
            vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int cur = 0;
        if (text1[ind1] == text2[ind2])
            cur = 1 + fun(ind1 - 1, ind2 - 1, text1, text2, dp);
        else {
            cur = max(fun(ind1 - 1, ind2, text1, text2, dp),
                      fun(ind1, ind2 - 1, text1, text2, dp));
        }
        return dp[ind1][ind2] = cur;
    }
    int fun_shifted_index(int ind1, int ind2, string text1, string text2,
                          vector<vector<int>>& dp) {
        if (ind1 == 0 || ind2 == 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int cur = 0;
        if (text1[ind1 - 1] == text2[ind2 - 1])
            cur = 1 + fun_shifted_index(ind1 - 1, ind2 - 1, text1, text2, dp);
        else {
            cur = max(fun_shifted_index(ind1 - 1, ind2, text1, text2, dp),
                      fun_shifted_index(ind1, ind2 - 1, text1, text2, dp));
        }
        return dp[ind1][ind2] = cur;
    }
    int longestCommonSubsequence(string text1, string text2) {

        // int m=text1.size();
        // int n=text2.size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return fun(m-1,n-1,text1,text2,dp);


        // int m=text1.size();
        // int n=text2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return fun_shifted_index(m,n,text1,text2,dp);


        // int m=text1.size();
        // int n=text2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // //base case is already have 0
        // for(int ind1=1;ind1<m+1;ind1++){
        //     for(int ind2=1;ind2<n+1;ind2++){
        //         int cur = 0 ;
        //         if(text1[ind1-1]==text2[ind2-1])
        //             cur = 1+dp[ind1-1][ind2-1];
        //         else
        //             cur = max( dp[ind1-1][ind2] , dp[ind1][ind2-1]);
        //         dp[ind1][ind2] = cur;
        //     }
        // }
        // return dp[m][n];


        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n + 1, 0);
        for (int ind1 = 1; ind1 < m + 1; ind1++) {
            vector<int> current(n + 1, 0);
            for (int ind2 = 1; ind2 < n + 1; ind2++) {
                int cur = 0;
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    cur = 1 + prev[ind2 - 1];
                else
                    cur = max(prev[ind2], current[ind2 - 1]);
                current[ind2] = cur;
            }
            prev = current;
        }
        return prev[n];
    }
};



// Recursion : 2^n , stack 
// memoization :  m*n , m*n + stack 
// tabulation :  m*n , m*n  
// space optimization :  m*n , n
