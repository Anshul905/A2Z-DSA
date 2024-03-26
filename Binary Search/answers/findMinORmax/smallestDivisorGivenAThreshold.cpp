int fun(vector<int>& nums, int m){
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
        sum += ceil( (double)(nums[i])/(double)(m));
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    if( nums.size() > threshold ) return -1;

    int maxi_element = *max_element(nums.begin(),nums.end());
    int divisor = maxi_element;
    int low = 1, high = maxi_element ;
    while( low<=high ){
        int  mid = low+(high-low)/2 ;
        int ret  = fun(nums, mid);
        if( ret <= threshold ){
            // if its possible, reduce the limit 
            divisor =  mid;
            high =  mid-1;
        }else{
            low = mid+1;
        }
    }
    return divisor;
}

// TC : log(max)*n
// SC : O(1)

// 1. find the h ?? h would be maximum element as minimum division's sum could be ( 1 + 1 + 1 +.... + n time =  n this is only possible when divisor is = maximum element 
// 2. if you dont use divisor variable low will be the answer 
