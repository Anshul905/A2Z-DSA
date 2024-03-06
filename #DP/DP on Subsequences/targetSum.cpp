
class Solution {
public:
    int fun(int ind, int target_sum, vector<int>& nums,
            vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target_sum == 0 && nums[0] == target_sum)
                return 2;
            if (target_sum == 0 && nums[0] != target_sum)
                return 1;
            if (target_sum != 0 && nums[0] == target_sum)
                return 1;
            return 0;
        }

        if (dp[ind][target_sum] != -1)
            return dp[ind][target_sum];

        int notTake = fun(ind - 1, target_sum, nums, dp);
        int take = 0;
        if (nums[ind] <= target_sum)
            take = fun(ind - 1, target_sum - nums[ind], nums, dp);

        return dp[ind][target_sum] = take + notTake;
    }

    int findTargetSumWays(vector<int>& num, int target) {
        // Recursion          : 2^(n)    , stack ( n )
        // memoization        : n*new_target , m*new_target + stack ( n )

        // int n = num.size();
        // int sum=0;
        // for(int i=0;i<n;i++)
        //     sum+=num[i];
        // int new_target = sum+target;

        // if(new_target%2)
        //     return 0;
        // else {
        //     new_target = new_target/2;
        //     vector<vector<int>> dp(n, vector<int>(new_target + 1, -1));
        //     int ans = fun(n - 1, new_target, num, dp);
        //     return ans;
        // }




        // tabular            : n*new_target , m*new_target

        // int n = num.size();
        // int sum=0;
        // for(int i=0;i<n;i++)
        //     sum+=num[i];
        // int new_target = sum+target;

        // if( new_target<0 || new_target%2)
        //     return 0;
        // else{
        //     new_target = new_target/2;
        //     vector<vector<int>> dp(n,vector<int>(new_target+1,0));

        //     if( num[0]<=new_target )
        //         dp[0][num[0]]=1;

        //     if(num[0]==0)
        //         dp[0][0]=2;
        //     else
        //         dp[0][0]=1;

        //     for(int ind=1;ind<n;ind++){
        //         for(int j=0;j<new_target+1;j++){
        //             int notTake = dp[ind-1][j];
        //             int take = 0;
        //             if(num[ind]<=j)
        //                 take = dp[ind-1][j-num[ind]];
        //             dp[ind][j] = take+notTake;
        //         }
        //     }

        //     int ans = dp[n-1][new_target];
        //     return ans;





        // space optimization : n*target , 2*target ( prev + cur )

        // int n = num.size();
        // int sum=0;
        // for(int i=0;i<n;i++)
        //     sum+=num[i];
        // int new_target = sum+target;

        // if( new_target<0 || new_target%2)
        //     return 0;
        // else{
        //     new_target = new_target/2;
        //     vector<int> prev(new_target+1,0);

        //     if( num[0]<=new_target )
        //         prev[num[0]]=1;
        //     if(num[0]==0)
        //         prev[0]=2;
        //     else
        //         prev[0]=1;

        //     for(int ind=1;ind<n;ind++){
        //         vector<int> cur(new_target+1,0);
        //         for(int j=0;j<new_target+1;j++){
        //             int notTake = prev[j];
        //             int take = 0;
        //             if(num[ind]<=j)
        //                 take = prev[j-num[ind]];
        //             cur[j] = take+notTake;
        //         }
        //         prev = cur;
        //     }

        //     return prev[new_target];
        // }



        // further space optimization : n*target , target ( prev )

        int n = num.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += num[i];
        int new_target = sum + target;

        if (new_target < 0 || new_target % 2)
            return 0;
        else {
            new_target = new_target / 2;
            vector<int> prev(new_target + 1, 0);

            if (num[0] <= new_target)
                prev[num[0]] = 1;
            if (num[0] == 0)
                prev[0] = 2;
            else
                prev[0] = 1;

            for (int ind = 1; ind < n; ind++) {
                for (int j = new_target; j >= 0; j--) {
                    int notTake = prev[j];
                    int take = 0;
                    if (num[ind] <= j)
                        take = prev[j - num[ind]];
                    prev[j] = take + notTake;
                }
            }

            return prev[new_target];
        }
    }
};




// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 
// tabular            : n*target , m*target
// space optimization : n*target , 2*target ( prev + cur )
// further space optimization : n*target , target ( prev )



// if(ind==0){
//     if( target_sum==0 && nums[0]==target_sum )
//         return 2;
//     if( target_sum==0 && nums[0]!=target_sum )
//         return 1;
//     if( target_sum!=0 && nums[0]==target_sum )
//         return 1;    
//     return 0;
// }


// if( num[0]<=new_target )
//     dp[0][num[0]]=1;

// if(num[0]==0)
//     dp[0][0]=2;
// else
//     dp[0][0]=1;


// Further space optimization????
// we dont right part of the prev so we will start storing new values in that part , for that we need to traverse from right ( because  for any cell we want prevs value before that index so it wont get override , while traversing right to left we are overriding the value which dont need in the left part )
