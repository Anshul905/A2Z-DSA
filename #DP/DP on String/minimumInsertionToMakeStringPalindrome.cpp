class Solution {
public:
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

    int minInsertions(string text1) {

        string text2 = text1;
        reverse(text2.begin(), text2.end());

        // int n=text1.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return n-fun_shifted_index(n,n,text1,text2,dp);

        // int n=text1.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // //base case is already have 0
        // for(int ind1=1;ind1<n+1;ind1++){
        //     for(int ind2=1;ind2<n+1;ind2++){
        //         int cur = 0 ;
        //         if(text1[ind1-1]==text2[ind2-1])
        //             cur = 1+dp[ind1-1][ind2-1];
        //         else
        //             cur = max( dp[ind1-1][ind2] , dp[ind1][ind2-1]);
        //         dp[ind1][ind2] = cur;
        //     }
        // }
        // return n-dp[n][n];

        int n = text1.size();
        vector<int> prev(n + 1, 0);
        for (int ind1 = 1; ind1 < n + 1; ind1++) {
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
        return n - prev[n];
    }
};


// Recursion : 2^n , stack 
// memoization :  n*n , n*n + stack 
// tabulation :  n*n , n*n  
// space optinization :  n*n , n

// if we know how many characters are present in palindrome subsequence , we substract it from length , so we will get to know no. of characters which needs to be paired 

// ans = n - lps()


// Intution : what part can i not touch??  when asking for min ... , ofc some bigger part which is common 
// we cant touch common part  so we substrat it from total