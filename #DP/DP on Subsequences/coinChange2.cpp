class Solution {
    int fun(int ind, int target_sum, vector<int>& nums,
            vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target_sum % nums[0] == 0)
                return 1;
            return 0;
        }

        if (dp[ind][target_sum] != -1)
            return dp[ind][target_sum];

        int notTake = fun(ind - 1, target_sum, nums, dp);
        int take = 0;
        if (nums[ind] <= target_sum)
            take = fun(ind, target_sum - nums[ind], nums, dp);

        return dp[ind][target_sum] = take + notTake;
    }

public:
    int change(int target, vector<int>& num) {

        // Recursion          : >>2^(n)    , >>stack ( n )  [ O(target)]
        // memoization        : n*target , n*target + >>stack ( n )  [
        // O(target)]


        // int n = num.size();
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return fun(n - 1, target, num, dp);





        // tabular            : n*target , n*target

        // int n=num.size();
        // vector<vector<int>> dp(n,vector<int>(target+1,0));
        // for(int j=0;j<target+1;j++){
        //     if(j%num[0]==0)
        //         dp[0][j]=1;
        //     else
        //         dp[0][j]=0;
        // }
        // for(int ind=1;ind<n;ind++){
        //     for(int j=0;j<target+1;j++){
        //         int notTake = dp[ind-1][j];
        //         int take = 0;
        //         if(num[ind]<=j)
        //             take = dp[ind][j-num[ind]];
        //         dp[ind][j] = take+notTake;
        //     }
        // }
        // return dp[n-1][target];




        // space optimization : n*target , target ( linear ) ( prev + cur )

        int n = num.size();
        vector<int> prev(target + 1, 0);
        for (int j = 0; j < target + 1; j++) {
            if (j % num[0] == 0)
                prev[j] = 1;
            else
                prev[j] = 0;
        }
        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(target + 1, 0);
            for (int j = 0; j < target + 1; j++) {
                int notTake = prev[j];
                int take = 0;
                if (num[ind] <= j)
                    take = cur[j - num[ind]];
                cur[j] = take + notTake;
            }
            prev = cur;
        }
        return prev[target];


        // further space optimization : n*target , target ( linear ) ( prev  )

        // vector<long> prev(target + 1, 0);
        // for (long j = 0; j < target + 1; j++) {
        //     if (j % num[0] == 0)
        //         prev[j] = 1;
        //     else
        //         prev[j] = 0;
        // }
        // for (long ind = 1; ind < n; ind++) {
        //     for (long j = 0; j < target + 1; j++) {
        //         long notTake = prev[j];
        //         long take = 0;
        //         if (num[ind] <= j)
        //             take = prev[j - num[ind]];
        //         prev[j] = take + notTake;
        //     }
        // }
        // return prev[target];

    }
};



// f(ind,target) dp[ind][target] --> ind index tak me weight = target ke kitna way ho sakte hai --> int  
// Recursion          : >>2^(n)    , >>stack ( n )  [ O(target)]
// memoization        : n*target , n*target + >>stack ( n )  [ O(target)]
// tabular            : n*target , n*target
// space optimization : n*target , target ( linear ) ( prev + cur )
// further space optimization : n*target , target ( linear ) ( prev  )


// Recursion          : >>2^(n)    , stack ( n ) ????
// TC : there is not only 2 path , you can still choose current one again  
// SC : coin is 1 wala , recursion space will be O(target)


// how further space optimization??
// we are storing cur in prev ( because ke us part ki jarurat nahi padegi hame to cur se usko update kar rahe hai )