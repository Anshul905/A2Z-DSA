int fun(vector<int>& nums, int low ,int high , int target){
    if(low>high)
        return -1;
    int mid = low+(high-low)/2;
    if(target==nums[mid])
        return mid ;
    else if(target>nums[mid])
        return fun(nums,mid+1,high,target);
    return fun(nums,low,mid-1,target);
}
int search(vector<int>& nums, int target) {
    
    //recursive
    return fun(nums,0,nums.size()-1,target);

    // iterative 
    // int n = nums.size();
    // int low = 0, high = n-1 ;
    // while(low<=high){
    //     int mid = low+(high-low)/2;
    //     if(target==nums[mid])
    //         return mid ;
    //     else if(target>nums[mid])
    //         low = mid+1;
    //     else
    //         high = mid-1;
    // }
    // return -1;

}


// TC : log(n)
// lets if the size of array is 32 ( you will get answer in 5 times i.e. 32 -> 16 -> 8 -> 4 -> 2 -> 1 )

// if you dont want to calculate mid as this 
//     int mid = low+(high-low)/2;
//     then you will have to use long long while assigning low and high 


// https://leetcode.com/problems/binary-search/