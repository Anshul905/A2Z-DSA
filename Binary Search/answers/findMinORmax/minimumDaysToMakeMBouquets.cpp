int fun(vector<int>& bloomDay, int mid, int m, int k) {
    int cnt = 0 ;
    int continous = 0;
    for(int i=0;i<bloomDay.size();i++){
        if( bloomDay[i]<=mid )
            continous++;
        else{
            cnt += (continous/k) ;
            continous = 0;
        }
    }
    if(continous)
        cnt += (continous/k) ;
    return cnt;
}


int minDays(vector<int>& bloomDay, int m, int k) {
    long long minFlowerNeeded = m*1LL  *  k*1LL ;
    if( minFlowerNeeded > bloomDay.size())
        return -1;

    //TC : log(maxElement-minElement)*n
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while(low<=high){
        int mid = low+(high-low)/2;
        int canMakeBouquets = fun(bloomDay,mid,m,k) ; 
    
        if( canMakeBouquets < m ){ //need more days 
            low = mid+1 ;
        }else{ //try to reduce the days 
            high = mid-1 ;
        }
    }
    return low; 
}


// similar concept as koko eating bananas 
// range will be days here ( low = min of array , high = max of array ) and apply binary search on that range 
