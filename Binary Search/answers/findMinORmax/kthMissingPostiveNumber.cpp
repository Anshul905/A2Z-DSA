int fun(vector<int>& arr, int key) {
    int n = arr.size();
    if( arr[0]>key )
        return key;
    if( key>arr[n-1] )
        return key-n;

    int l=0 , h=n-1;
    while(l<=h){    
        int m = l+(h-l)/2 ;
        if( arr[m]<key )
            l=m+1;
        else
            h=m-1;
    }        
    int smallerElementThanKey = l;
    if(arr[l]==key)        
        smallerElementThanKey += 1;
    return key-smallerElementThanKey;
}

int findKthPositive(vector<int>& arr, int k) {

    // (n,1)
    // int ans = k ;
    // for(int i=0;i<arr.size();i++){
    //     //there is some number lesser or equal than ans, so possible answer could be ans+1
    //     if(ans>=arr[i])
    //         ans++;
    //     else
    //         break;
    // }
    // return ans;




    // ( log(maxi_element) * log(n) == log(n)*log(n), 1 ) 
    // since maxi_element<=n for sure
    // int n = arr.size(); 
    // int low = k, high = arr[n-1]+k;
    // while (low <= high) {
    //     int mid = low + (high - low) / 2;
    //     int ret = fun(arr, mid);
    //     // ret = no. of missing element less than equal to k
    //     if (ret >= k) {
    //         high = mid - 1;
    //     } else {
    //         low = mid + 1;
    //     }
    // }
    // return low;



    // log(n),1
    int n = arr.size();
    int low = 0, high = n-1 ;
    int missing = 0;
    while(low<=high){
        cout<<high<<endl;
        int mid = low+(high-low)/2;
        missing = arr[mid]-(mid+1);
        if( missing < k )
            low = mid+1;
        else
            high = mid-1;
    }
    //high will be pointing to left boundry of range where k lie

    // if(high==-1)
    //     return k;
    // int missingAtHigh = arr[high]-(high+1);
    // return arr[high]+(k-missingAtHigh);
    // or
    // return arr[high]+(k-(arr[high]-(high+1))) ===  arr[high] + k - arr[high] + high + 1  ===  k + high + 1 = k + low 
    return k+low;
}

// ( n*n , n)
// ( n , 1)
// ( log(n)*log(n) , 1)
// ( log(n) , 1)

// use map ( n+ maxi_element*n ~~ n*n , n )

// traverse array (n,1)
// K + smalller than k element , increase k if some element is not greater   

// TC : log(maxi_element) * log(n) since maxi_element<=n so log(n)*log(n)
// SC : O(1)



// ( log(n) , 1)
// arr =  [2,3,4,7,11], k = 5
// mis =  [1,1,1,3,6] , no need to store it it is just arr[i]-(i+1)
// apply binary search on arr and find where k would be ,compare with no. of missing value   
// at the end high will be pointing to the left boundary  ( where missing value must be less than k)

