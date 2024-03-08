pair<int, int> getFloorAndCeil(vector<int> &nums, int n, int target) {
	
	pair<int,int> ans;

    int low = 0, high = n-1 ;
	int temp = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
		if(target<nums[mid])
            high = mid-1;
        else{
            low = mid+1;
			temp = mid ;
		}
    }
	ans.first = (temp==-1 ? -1 : nums[temp]) ;
	
	int ind = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
	ans.second = (ind==n ? -1 : nums[ind]) ;

	return ans;
}


// https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401