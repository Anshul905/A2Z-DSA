bool searchMatrix(vector<vector<int>>& matrix, int target) {
   
	// TC : m*log(n)
	// go to each row , apply binary search 

	// TC : O(m+n)
	int m=matrix.size();
	int n=matrix[0].size();
	int i=0,j=n-1;
	while(i<=m-1 && j>=0){
		if(matrix[i][j]==target)
			return true;
		if(matrix[i][j]>target)
			j--;
		else
			i++;
	}
	return false;
}
