long long fun(vector<int>& piles, int mid){
    long long cnt=0;
    for(int a:piles){
        cnt += a/mid;
        if( a%mid > 0 )
            cnt++ ;
    }
    return cnt;
}

int minEatingSpeed(vector<int>& piles, int h) {


    //TC : log(maxElement)*n
    int low=1;
    int high = *max_element(piles.begin(), piles.end());
    while(low<=high){
        long long mid = low+(high-low)/2;
        long long reqTime = fun(piles,mid) ; 
        
        if( reqTime > h ){ //eating slow 
            low = mid+1 ;
        }else{ //eating okay or fast , try to eat slow 
            high = mid-1 ;
        }
    }
    return low; 
}


// we need to find speed here and 
//     we are pretty sure that koko can eat all the bananas of a specific pile in at least 1 hour so maximum speed ne highest number of banana in any pile 
//     so our max is maximum from all the pile ( anyway problem will also be solved if you take INT_MAX )
//     ans minimum speed has to be 1 ( if 0 means not eating at ell but he has to finish all )

// at some point ( mid )
//     we will check if he is eating slow/fast 
//     if slow , tell eat fast and vice versa  

