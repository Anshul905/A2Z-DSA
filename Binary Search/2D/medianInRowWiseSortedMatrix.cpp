int upperBound(vector<int> &nums , int x){

    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();
    while(low<=high){
        int mid = low + (high - low) / 2;
        if( nums[mid]<=x )
            low = mid+1;
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}   


int countSmallEqual(vector<vector<int>> &matrix, int m , int n , int x){
    int cnt=0;
    for(int i=0;i<m;i++){
        // vector<int> temp = matrix[i];
        // cnt += upper_bound(temp.begin(),temp.end(), x) - temp.begin();
        cnt += upperBound(matrix[i],x);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {

    // get low and high 
    int low = INT_MAX ;
    int high = INT_MIN ;
    for(int i=0;i<m;i++){
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][n-1]);
    }

    //get the smaller number such that no. of elements in the array <= number in the matrix > (m*n)/2 ; 
    int ans = 0 ;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        //get the number of elements that are <= mid in the matrix ( n*log(m) )
        int smallEqual = countSmallEqual(matrix,m,n,mid);

        if (smallEqual > (m * n) / 2) { // there might be some smaller number which can still satisfy the condition
            ans = mid;
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}


// Brute : 
//     TC : m*n + m*n*log(m*n)  
//     SC : m*n ( 1 d array )


// TC : log(1e9) + m*log(n) == 32*m*log(n)

// 1. figure out the min and max from the matrix ???
//     low = min from first column
//     high = max from last column
//     so basically now minimum number to maximum number is range 


//       1 2 2 3  4  5 5 6 7 
//       1 2 4 4  4  5 5 6 7 
//       1 2 2 3  4  4 5 6 7 
//       1 2 2 4  4  4 4 6 7 
//       no of element <= 4 is (5,5,6,7) ( which will be always be more than 9/2 == (m*n)/2 )

// 2.   find the smallest number such that [no. of element in the matrix <= number ] > (m*n)/2


