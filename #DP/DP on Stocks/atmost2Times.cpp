class Solution {
public:
    int funTransaction(int ind, int n, int transaction, vector<int>& prices,
                       vector<vector<int>>& dp) {
        if (ind == n)
            return 0;
        if (transaction == 4)
            return 0;

        if (dp[ind][transaction] != -1)
            return dp[ind][transaction];

        int profit = 0;
        if (transaction % 2 == 0) {
            profit =
                max(-prices[ind] +
                        funTransaction(ind + 1, n, transaction + 1, prices, dp),
                    0 + funTransaction(ind + 1, n, transaction, prices, dp));
        } else {
            profit =
                max(prices[ind] +
                        funTransaction(ind + 1, n, transaction + 1, prices, dp),
                    0 + funTransaction(ind + 1, n, transaction, prices, dp));
        }
        return dp[ind][transaction] = profit;
    }

    int fun(int ind, int buy, int n, int k, vector<int>& prices,
            vector<vector<vector<int>>>& dp) {
        if (ind == n)
            return 0;
        if (k == 0)
            return 0;

        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + fun(ind + 1, 0, n, k, prices, dp),
                         0 + fun(ind + 1, 1, n, k, prices, dp));
        } else {
            profit = max(prices[ind] + fun(ind + 1, 1, n, k - 1, prices, dp),
                         0 + fun(ind + 1, 0, n, k, prices, dp));
        }
        return dp[ind][buy][k] = profit;
    }

    int maxProfit(vector<int>& prices) {

        // memoization : n*2*3 , n*2*3 +stack
        // int n= prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1))
        // ); return fun(0,1, n,2,prices,dp);



        // tabulation : n*2*3 ,n*2*3
        // int n= prices.size();
        // vector<vector<vector<int>>>
        // dp(n+1,vector<vector<int>>(2,vector<int>(3,0))  );
        // for(int buy=0;buy<2;buy++){
        //     for(int k=0;k<=2;k++){
        //         dp[n][buy][k]=0;
        //     }
        // }
        // for(int ind=n-1;ind>=0;ind--){
        //     for (int buy = 0; buy < 2; buy++){
        //         dp[ind][buy][0]=0;
        //     }
        // }
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<2;buy++){
        //         for(int k=1;k<=2;k++){
        //             int profit=0;
        //             if(buy){
        //                 profit = max( -prices[ind]+dp[ind+1][0][k] ,
        //                 dp[ind+1][1][k]  );
        //             }else{
        //                 profit = max( prices[ind]+dp[ind+1][1][k-1] ,
        //                 dp[ind+1][0][k]  );
        //             }
        //             dp[ind][buy][k] = profit ;
        //         }
        //     }
        // }
        // return  dp[0][1][2];




        // space optimization : n*2*3 , 2*3
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            vector<vector<int>> cur(2, vector<int>(3, 0));
            for (int buy = 0; buy < 2; buy++) {
                for (int k = 1; k <= 2; k++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[ind] + next[0][k], next[1][k]);
                    } else {
                        profit = max(prices[ind] + next[1][k - 1], next[0][k]);
                    }
                    cur[buy][k] = profit;
                }
            }
            next = cur;
        }
        return next[1][2];



        // memoization n*4 , n*4 + stack
        // int n= prices.size();
        // vector<vector<int>> dp(n,vector<int>(4,-1));
        // return funTransaction(0,n,0,prices,dp);



        // tabulation n*4 , n*4
        // int n= prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(5,0));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int t=3;t>=0;t--){
        //         int profit=0;
        //         if(t%2==0){
        //             profit = max( -prices[ind]+dp[ind+1][t+1] ,
        //             dp[ind+1][t]  );
        //         }else{
        //             profit = max( prices[ind]+dp[ind+1][t+1] ,
        //             dp[ind+1][t]  );
        //         }
        //         dp[ind][t] = profit ;
        //     }
        // }
        // return dp[0][0];



        // space optimization n*4 , 4
        // int n= prices.size();
        // vector<int> next(5,0);

        // for(int ind=n-1;ind>=0;ind--){
        //     vector<int> cur(5,0);
        //     for(int t=3;t>=0;t--){
        //         int profit=0;
        //         if(t%2==0){
        //             profit = max( -prices[ind]+next[t+1] ,
        //             next[t]  );
        //         }else{
        //             profit = max( prices[ind]+next[t+1] ,
        //             next[t]  );
        //         }
        //         cur[t] = profit ;
        //     }
        //     next = cur;
        // }
        // return next[0];
    }
};




// two type of solution 
//     3d dp : n*2*3 ( ind*buy*k ) 
//         memoization : n*2*3 , n*2*3 +stack
//         tabulation : n*2*3 ,n*2*3
//         space optimization : n*2*3 , 2*3

//     2d dp : n*4 ( ind*transaction )
//         memoization n*4 , n*4 + stack
//         tabulation n*4 , n*4
//         space optimization n*4 , 4
