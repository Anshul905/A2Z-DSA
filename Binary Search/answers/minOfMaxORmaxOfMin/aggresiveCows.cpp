int fun(vector<int>& stalls, int distance   , int cows){
    int n = stalls.size();
    int canPlaceAt = stalls[0]+distance;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if( stalls[i]>=canPlaceAt ){
            cnt++;
            canPlaceAt = stalls[i]+distance;
        }
        if(cnt==cows)
            break ;
    }
    return cnt;
}


int aggressiveCows(vector<int> &stalls, int k)
{
        sort(stalls.begin(),stalls.end());

        int n = stalls.size();
        // low can be increased --> min of all consecutive diff [ 2,4,8,11] = min(2,4,3) = 2
        int low = 1 , high = stalls[n-1]-stalls[0] ;
        int ans= 0 ;
        while( low<=high ){
            int  mid = low+(high-low)/2 ;
            int ret  = fun(stalls, mid , k);
            if( ret >= k ){
                // if its possible, increase the limit 
                ans = mid;
                low = mid+1;
            }else{
                high =  mid-1;
            }
        }
        return ans;
}

// min(max) or max(min)

// TC : log( maxElement-minElement+1)*n
// SC : o(1)