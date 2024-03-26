int mySqrt(int x) {
    int low=0,high=x;
    while(low<=high){
        long long mid = low+(high-low)/2;
        long long sq = mid*mid ; 
        if( sq > x ){
            high = mid-1 ;
        }else{
            low = mid+1 ;
        }
    }
    return high;
}

// take long long as it can overflow 