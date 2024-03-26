
#include <bits/stdc++.h>
int kthElement(vector<int> &nums1, vector<int>& nums2, int n, int m, int k){
 

        // in brute force take array of m+n size , put all , return (k-1)th element  ( n+m , n+m )

        //Better ( n+m , 1 ) 
        // int i=0, j=0;
        // int cnt = 0;;
        // while( i<=n-1 && j<=m-1 ){
        //     if( nums1[i]<nums2[j] ){
        //         cnt++;
        //         if(cnt==k){
        //             return nums1[i];
        //         }
        //         i++;
        //     }else{
        //         cnt++;
        //         if(cnt==k){
        //             return nums2[j];
        //         }
        //         j++;
        //     }
        // }
        // while(i<=n-1){
        //         cnt++;
        //         if(cnt==k){
        //             return nums1[i];
        //         }
        //         i++;
        // }
        // while(j<=m-1){
        //         cnt++;
        //         if(cnt==k){
        //             return nums2[j];
        //         }
        //         j++;
        // }

            // optimal solution : log( min(n,m) )
            if(n>m)
                return kthElement(nums2,nums1,m,n,k);
            
            int symmetry_size = k;
            // int low=0, high=n;
            int low = max(0,k-m);
            int high = min(n,k);
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
                    return first;
                }
            }
            return -1;
 }

 
// why not  low=0 and high=n;
// what if k>m, in the median problem median will be (m+n+1)/2 , so there was no tension of this because m was always >= symmetry_size
// but here k can be greater than m , so low = max(0,k-m);
// high is not n because what if k<n and if we select more number of element than k from nums1 
// then we would have to ask for negative no. of element from nums2  so high = min(n,k);
// so 
// int low = max(0,k-m);
// int high = min(n,k);
