int search(vector<int>& nums, int target) {
    
    int high = nums.size()-1 ;
    int low = 0 ;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==target)
            return mid;

        if( nums[low]<=nums[mid] ){
            if( nums[low]<=target && target<=nums[mid] )
                high = mid-1;
            else
                low = mid+1;
        }else{
            if( nums[mid]<=target && target<=nums[high] )
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}


// https://leetcode.com/problems/search-in-rotated-sorted-array/


// https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/

// we will follow a simple two-step process. 
// First, we identify the sorted half of the array. 
// Once found, we determine if the target is located within this sorted half. 
//     If not, we eliminate that half from further consideration. 
//     Conversely, if the target does exist in the sorted half, we eliminate the other half.