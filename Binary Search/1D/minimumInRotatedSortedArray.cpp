int findMin(vector<int>& nums) {

    int high = nums.size()-1 ;
    int low = 0 ;
    int ans=INT_MAX;
    while(low<=high){
        int mid = low+(high-low)/2;
                
        // optimization - if the search space is already sorted ( both halves sorted ) -> nums[] will be minimum from search space 
        if( nums[low]<=nums[high] ){
            ans = min(ans,nums[low]);
            break;
        }


        if( nums[low]<=nums[mid] ){
            //pick up the minimum( nums[low] is minimum in this sorted half ) and move right 
            ans = min(ans,nums[low]);
            low = mid+1;
        }else{
            //pick up the minimum( nums[mid] is minimum in this sorted half ) and move left 
            ans = min(ans,nums[mid]);
            high = mid-1;
        }

    }
    return ans;

}

// One of the half will always be sorted 
// pick the minimum from the sorted half and move towards another half 


// pre-requisite : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// can extend this problem for duplicates 