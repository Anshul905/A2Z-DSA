#include <bits/stdc++.h>
int count(vector<int>& nums, int n, int target) {

        int lb = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
        if( lb==n || nums[lb]!=target )
            return 0;
        else{
            int ub = upper_bound(nums.begin(),nums.end(), target) - nums.begin();
            return ub-lb;
        }

}

// https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456