int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(),nums.end(),target)-nums.begin();

    //same code as lowerbound , smallest index such that nums[ind]>=target 
}


// https://leetcode.com/problems/search-insert-position/description/