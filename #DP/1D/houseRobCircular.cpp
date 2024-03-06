int solve(vector<int>& nums) {
    int n = nums.size();
    int prev2;
    int prev = nums[0];
    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i >= 2)
            pick += prev2;
        int notPick = 0 + prev;

        int cur = max(pick, notPick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int rob(vector<int>& nums) {

    //   first and last should not be connected
    if (nums.size() == 1)
        return nums[0];
    vector<int> exceptFirst(nums.begin() + 1, nums.end());
    vector<int> exceptLast(nums.begin(), nums.end() - 1);

    return max(solve(exceptFirst), solve(exceptLast));
}



// like maximum sum of non-adjacent element problem , but here is the twist ( first and last cant be picked together )
// so ??  answer will be max(  0 to n-2 , 1 to n-1  )

// pattern -> subsequence ( pick or not pick )
// recursion (2^n,stack)-> memoization (n,n+stack)-> tabular (n,n)-> space optimization (n,1) 

// ( 0 to n-2 ) --> last element is not included fort sure , now if you want to take first take or not [ that depends on maximum sum whether it will included or not ]
// similarly for ( 1 to n-1 ) , first is not included for sure , last might be 