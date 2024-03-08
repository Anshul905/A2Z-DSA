int findKRotation(vector<int> &nums){
        int high = nums.size()-1 ;
        int low = 0 ;
        int ans=1e9+2;
        int ansInd = 0 ;
        while(low<=high){
            int mid = low+(high-low)/2;
                    
            if( nums[low]<=nums[high] ){
                if(nums[low]<ans){
                    ans = nums[low];
                    ansInd = low ;
                }
                break;
            }

            if( nums[low]<=nums[mid] ){
                if(nums[low]<ans){
                    ans = nums[low];
                    ansInd = low ;
                }
                low = mid+1;
            }else{
                if(nums[mid]<ans){
                    ans = nums[mid];
                    ansInd = mid ;
                }
                high = mid-1;
            }

        }
        return ansInd;
}


// pre-requisite : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ 


// can extend this problem for duplicates 