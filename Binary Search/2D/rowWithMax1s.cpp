int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int i=0,j=m-1;
    int ind=-1;
    while(i<=n-1 && j>=0){
        if(matrix[i][j]==1){
            j--;
            ind=i;
        }else{
            i++;
        }
    }
    return ind;
}

// n*log(m) --> for each row, get the index of first 1 
// n+m : this solution 