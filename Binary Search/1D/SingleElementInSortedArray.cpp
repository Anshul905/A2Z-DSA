int singleNonDuplicate(vector<int>& nums) {

    // (n,1)
    // int xorArray = 0 ;
    // for(int i=0;i<nums.size();i++)
    //     xorArray ^= nums[i];
    // return xorArray;


    //binary -- my thought  
    int high = nums.size()-1 ;
    int low = 0 ;
    while(low<=high){
        int mid = low+(high-low)/2;                    
        if( mid-1>=low && nums[mid]==nums[mid-1] ){
            if( (mid-low)%2==0 )
                high = mid-2;
            else
                low = mid+1 ;
        }else if( mid+1<=high && nums[mid]==nums[mid+1] ) {
            if( (high-mid)%2==0 )
                low = mid+2;
            else
                high = mid-1 ;
        }else{
            return nums[mid];
        }
    }
    return -1;
}


// I checked
//     if array can have index (mid-1) or not
//     if it is then check if nums[mid] is equal to its left element(nums[mid-1]) or not
//     same thing with the right side (mid and mid+1)
// then i thought of length of left half and right half based on comparasion between nums[mid] , nums[mid-1] and nums[mid+1]

