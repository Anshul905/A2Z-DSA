bool fun(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {

    if (target == 0)
        return true;
    if (i == 0)
        return (arr[0] == target);

    if (dp[i][target] != -1)
        return dp[i][target];

    bool notTake = fun(i - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[i])
        take = fun(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = (take || notTake);
}

bool canPartition(vector<int>& arr) {
    
    // int n = arr.size();
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    //     sum += arr[i];
    // if (sum % 2) {
    //     return false;
    // } else {
    //     vector<vector<int>> dp(n, vector((sum / 2) + 1, -1));
    //     return fun(n - 1, sum / 2, arr, dp);
    // }





    // int n = arr.size();
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    //     sum += arr[i];
    // if (sum % 2) {
    //     return false;
    // } else {
    //     vector<vector<int>> dp(n, vector((sum / 2) + 1, 0));
    //     for (int i = 0; i < n; i++)
    //         dp[i][0] = true;
    //     if (arr[0] <= (sum / 2))
    //         dp[0][arr[0]] = true;

    //     for (int i = 1; i < n; i++) {
    //         for (int j = 1; j < (sum / 2) + 1; j++) {
    //             bool notTake = dp[i - 1][j];
    //             bool take = false;
    //             if (j >= arr[i])
    //                 take = dp[i - 1][j - arr[i]];

    //             dp[i][j] = take || notTake;
    //         }
    //     }
    //     return dp[n - 1][sum / 2];
    // }




    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2) {
        return false;
    } else {

        vector<int> prev((sum / 2) + 1, false);
        if (arr[0] <= (sum / 2))
            prev[arr[0]] = true;
        prev[0] = true;

        for (int i = 1; i < n; i++) {
            vector<int> cur((sum / 2) + 1, false);
            for (int j = 0; j < (sum / 2) + 1; j++) {
                bool notTake = prev[j];
                bool take = false;
                if (j >= arr[i])
                    take = prev[j - arr[i]];

                cur[j] = take || notTake;
            }
            prev = cur;
        }
        return prev[(sum / 2)];
    }
}


// Recursion          : 2^(n)    , stack ( n ) 
// memoization        : n*target , m*target + stack ( n ) 
// tabular            : n*target , m*target
// space optimization : n*target , target

