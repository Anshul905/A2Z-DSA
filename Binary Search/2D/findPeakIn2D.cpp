vector<int> findPeakGrid(vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();
	int low=0;
	int high=n-1;

	while(low<=high){
		int mid = low + (high - low) / 2;
		//find max from mid column
		int maxInd = -1 ;
		int maxi = 0 ;
		int i=0;
		for(i=0;i<m;i++){
			if( mat[i][mid] > maxi  ){
				maxi = mat[i][mid] ;
				maxInd = i;
			}
		} 
		if( mid-1>=low && mat[maxInd][mid-1]>mat[maxInd][mid]  )
			high = mid-1;
		else if( mid+1<=high && mat[maxInd][mid]<mat[maxInd][mid+1] )
			low = mid+1 ;
		else
			return {maxInd,mid};

	}
	return {-1,-1};
}


// intution from peak element in 1d array : https://leetcode.com/problems/find-peak-element/description/

// select max from mid columns 
//     that element must be greater than above and down cell 
//     now check for its left and right just like 1d array 

// basically we trimmed down 2d problem to 1d by selecting column with index mid 
