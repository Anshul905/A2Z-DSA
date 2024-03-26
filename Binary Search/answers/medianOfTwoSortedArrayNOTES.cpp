double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Brute solution :  ( m+n , m+n )
        // int n=nums1.size() , m=nums2.size() ;
        // int l=0, r=0;
        // vector<int> v ;
        // while( l<=n-1 && r<=m-1 ){
        //     if(nums1[l] <= nums2[r]) v.push_back(nums1[l++]);
        //     else v.push_back(nums2[r++]);
        // }
        // while( l<=n-1)
        //     v.push_back(nums1[l++]);
        // while( r<=m-1)
        //     v.push_back(nums2[r++]);

        // if( (m+n)%2==1 )
        //     return v[(m+n)/2];
        // return ((double)(v[((m+n)/2) - 1]) + (double)(v[(m+n)/2]))/2.0;




        // Better solution :  ( m+n , 1 )
        // int n=nums1.size() , m=nums2.size() ;
        // int l=0, r=0;
        // int cnt = 0 , first = -1 , second = -1;
        // int s = (m+n)/2 ;
        // int f = ((m+n)/2) - 1  ;

        // while( l<=n-1 && r<=m-1 ){
        //     if(nums1[l] <= nums2[r]){
        //         if( cnt == s )second = nums1[l]; 
        //         if( cnt == f )first = nums1[l]; 
        //         cnt++;
        //         l++;
        //     }else{
        //         if( cnt == s )second = nums2[r]; 
        //         if( cnt == f ) first = nums2[r]; 
        //         cnt++;
        //         r++;
        //     }
        // }
        // while(l<=n-1){
        //     if( cnt == s )second = nums1[l]; 
        //     if( cnt == f ) first = nums1[l]; 
        //     cnt++;
        //     l++;
        // }
        // while(r<=m-1){
        //     if( cnt == s )second = nums2[r]; 
        //     if( cnt == f ) first = nums2[r]; 
        //     cnt++;
        //     r++;
        // }

        // if( (m+n)%2==1 )
        //     return second;
        // return ((double)(first) + (double)(second))/2.0;




        // optimal solution : log( min(n,m) )
        int n = nums1.size() , m = nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);
        
        int symmetry_size = (n+m+1)/2;
        int low=0, high=n;
        while(low<=high){
            int mid = low+(high-low)/2;
            int l1 = mid-1, r1 = mid;
            int l2 = symmetry_size-mid-1 , r2 = symmetry_size-mid;
            if( l1>=0 && r2<=m-1 && nums1[l1]>nums2[r2] )
                high = mid-1;
            else if( l2>=0 && r1<=n-1 && nums2[l2]>nums1[r1] )
                low = mid+1;
            else{
                int left1 = INT_MIN;
                int left2 = INT_MIN;
                if(l1>=0) left1 = nums1[l1];
                if(l2>=0) left2 = nums2[l2];
                int first = max( left1, left2 );
                
                int right1 = INT_MAX;
                int right2 = INT_MAX;
                int right2 = INT_MAX;
                if(r1<=n-1) right1 = nums1[r1];
                if(r2<=m-1) right2 = nums2[r2];
                int second = min( right1, right2 );
                
                if( (m+n)%2==1 )
                    return first;
                return ((double)(first) + (double)(second))/2.0; 
            }
        }
        return -1;
}

