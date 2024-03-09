
int lowerBound(vector<int> nums, int n, int target) {
	
	// return lower_bound(nums.begin(),nums.end(), target) - nums.begin();

    int low = 0, high = n-1 ;
	int ans = n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(target>nums[mid])
            low = mid+1;
        else{
            high = mid-1;
            // keep the ans because we dont if there is any possible answer in left side or not 
			ans = mid; 
		}
    }
    return ans;
}

int upperBound(vector<int> &nums, int target, int n){

	// return upper_bound(nums.begin(),nums.end(), target) - nums.begin();

    int low = 0, high = n-1 ;
	int ans = n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(target>=nums[mid])
            low = mid+1;
        else{
            high = mid-1;
			ans = mid;
		}
    }
    return ans;

}
// you can also return low, it can also be the answer 




// lower bound --> smallest index such nums[ind]>=target , 
    // if target<nums[0] , return 0
    // if target>nums[n-1] , return n

// upper bound --> smallest index such nums[ind]>target 
    // if target<nums[0] , return 0
    // if target>nums[n-1] , return n

// https://www.codingninjas.com/studio/problems/lower-bound_8165382
// https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383
