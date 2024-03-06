class Solution {
    int fun(int ind, int buy, int n, vector<int>& prices,
            vector<vector<int>>& dp) {
        if (ind >= n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + fun(ind + 1, 0, n, prices, dp),
                         0 + fun(ind + 1, 1, n, prices, dp));
        } else {
            profit = max(prices[ind] + fun(ind + 2, 1, n, prices, dp),
                         0 + fun(ind + 1, 0, n, prices, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {

        // memoization :  n*2 , n*2 + stack
        // int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return fun(0,1, n, prices,dp);


        // tabulation :  n*2 , n*2
        // int n=prices.size();
        // vector<vector<int>> dp(n+2,vector<int>(2,0));
        // dp[n] = {0,0};

        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<2;buy++){
        //         int profit=0;
        //         if(buy){
        //             profit = max( -prices[ind]+dp[ind+1][0] , dp[ind+1][1] );
        //         }else{
        //             profit = max( prices[ind]+dp[ind+2][1] , dp[ind+1][0]  );
        //         }
        //         dp[ind][buy] = profit ;
        //     }
        // }
        // return  dp[0][1];




        // space optimization :  n*2 , 2
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> next2(2, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> cur(2, 0);
            for (int buy = 0; buy < 2; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + next[0], next[1]);
                } else {
                    profit = max(prices[ind] + next2[1], next[0]);
                }
                cur[buy] = profit;
            }
            next2 = next;
            next = cur;
        }
        return next[1];
    }
};


// b....s colldown(1 day) b.....s no limit 

// memoization :  n*2 , n*2 + stack 
// tabulation :  n*2 , n*2  
// space optimization :  n*2 , 2*3  

// i dont think greedy can work here but greedy works for multiple transaction without condition 
// 1 2 3 0 2 
//     greedy (3-1)+cooldown+(2-2)=2
//     ans =  (2-1)+cooldown+(2-0)=3