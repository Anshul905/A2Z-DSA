
vector<int> searchRange(vector<int>& nums, int target) {

//     vector<int> ans(2,-1);
//     int n = nums.size();
//     int low = 0, high = n-1 ;
//     while(low<=high){
//         int mid = low+(high-low)/2;
//         if(target==nums[mid]){
//             ans[0] =  mid ;
//             high = mid-1;
//         }else if(target>nums[mid])
//             low = mid+1;
//         else
//             high = mid-1;
//     }


//     if(ans[0]==-1)
//         return {-1,-1};

//     low = 0, high = n-1 ;
//     while(low<=high){
//         int mid = low+(high-low)/2;
//         if(target==nums[mid]){
//             ans[1] =  mid ;
//             low = mid+1;
//         }else if(target>nums[mid])
//             low = mid+1;
//         else
//             high = mid-1;
//     }

// return ans;




    int lb = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
    if( lb==nums.size() || nums[lb]!=target )
        return {-1,-1};
    else{
        int ub = upper_bound(nums.begin(),nums.end(), target) - nums.begin();
        return {lb,ub-1};
    }


}
