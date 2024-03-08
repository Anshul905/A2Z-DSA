int search(vector<int>& nums, int target) {
    
    int high = nums.size()-1 ;
    int low = 0 ;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==target)
            return mid;

        // [ 3 3 1 3 3 3 3 3 ] (arr of low,mid,high)all are 3 , we cant decide which half is sorted by looking at nums[low],nums[mid] and nums[high]
        if( nums[low]==nums[mid] && nums[mid]==nums[high] ){
            high--;
            low++;
            continue;
        }

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



// https://takeuforward.org/arrays/search-element-in-rotated-sorted-array-ii/
// extension of https://leetcode.com/problems/search-in-rotated-sorted-array/


// unique wala code will fail for this condition [ 3 3 1 3 3 3 3 3 ]   
// Additional code : 
// [ 3 3 1 3 3 3 3 3 ] (arr of low,mid,high)all are 3 , we cant decide which half is sorted by looking at nums[low],nums[mid] and nums[high]
// if( nums[low]==nums[mid] && nums[mid]==nums[high] ){
//     high--;
//     low++;
//     continue;
// }


// we will follow a simple two-step process. 
// First, we identify the sorted half of the array. 
// Once found, we determine if the target is located within this sorted half. 
//     If not, we eliminate that half from further consideration. 
//     Conversely, if the target does exist in the sorted half, we eliminate the other half.

