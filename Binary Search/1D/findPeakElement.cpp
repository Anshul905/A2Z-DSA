int findPeakElement(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){
        int mid = low+(high-low)/2 ;

        if( mid-1>=low && nums[mid-1]>nums[mid] )
            high = mid-1;
        else if( mid+1<=high && nums[mid]<nums[mid+1] )
            low = mid+1;
        else
            return mid;
    } 
    return -1;
}

// This code works with both if array has one peak or multiple peaks.

// if the nums[mid-1] > nums[mid] then eliminates the right part 
// similarly if nums[mid+1] > nums[mid] then eliminates the left part
// if none of the above condition matched that means nums[mid-1] < nums[mid] < nums[mid+1]