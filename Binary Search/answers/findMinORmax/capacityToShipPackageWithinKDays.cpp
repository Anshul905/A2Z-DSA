int fun(vector<int>& weights, int m){
    int sum = 0;
    int noOfDay = 0;
    for(int i=0; i<weights.size(); i++){
        sum += weights[i];
        if(sum>m){
            noOfDay++;
            sum = weights[i];
        }
    }
    noOfDay++;
    return noOfDay;
}


int shipWithinDays(vector<int>& weights, int days) {

    int maxi_element = *max_element(weights.begin(),weights.end());
    int sum = accumulate(weights.begin(),weights.end(),0);
    int low = maxi_element , high = sum ;
    int minDay = high;
    while( low<=high ){
        int  mid = low+(high-low)/2 ;
        int ret  = fun(weights, mid);
        if( ret <= days ){
            // if its possible, reduce the limit 
            minDay =  mid;
            high =  mid-1;
        }else{
            low = mid+1;
        }
    }
    return minDay;
}

// TC : log(sum-max+1) * n
// SC : O(1)

// low is maximum_sum because we can not load weight than the maximum weight capacity of the ship, 
// so if low (5) was less than maximum_element (10), that package would not have been delivered  
// high is sum when days = 1 