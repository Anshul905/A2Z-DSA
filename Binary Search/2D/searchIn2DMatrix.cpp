bool searchMatrix(vector<vector<int>>& matrix, int target) {
  
	// TC : n+log(m)
	// int m=matrix.size();
	// int n=matrix[0].size();
	// for(int i=0;i<m;i++){
	//     if( matrix[i][0]<=target && matrix[i][n-1]>=target ){
	//         int low=0;
	//         int high=n-1;
	//         while(low<=high){
	//             int mid = low+(high-low)/2;
	//             if(matrix[i][mid] == target)
	//                 return true;
	//             if( matrix[i][mid] > target  )
	//                 high = mid-1;
	//             else
	//                 low = mid+1;
	//         }
	//     }
	// }
	// return false;

	// TC : log(m*n)
	int m=matrix.size();
	int n=matrix[0].size();
	int low=0;
	int high=m*n-1;
	while(low<=high){
		int mid = low+(high-low)/2;
		int i=mid/n;
		int j=mid%n;
		if(matrix[i][j] == target)
			return true;
		if( matrix[i][j] > target  )
			high = mid-1;
		else
			low = mid+1;
	}
	return false;
}


// m+log(n) ==> go to each row and check if target comes under that rows range then search if it is present 
// 	row : 10 20 30 4 0
// 	target might not be there eg. : 35 , return false 
// log(m*n) ==> flat the 2d array to 1d array ( use divide and remainder )