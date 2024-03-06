#include <bits/stdc++.h> 
int fun(int i, int j1, int j2 , int r, int c , vector<vector<vector<int>>>& dp,vector<vector<int>>& mat) {

    if( j1<0 || j1>c || j2<0 || j2>c  )
        return -1e8;

    if (i == r){
        if(j1==j2)
            return  mat[i][j1];
        else
            return mat[i][j1]+mat[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = 0;
    for(int l=-1;l<=1;l++){
        for(int k=-1;k<=1;k++){
            int cur = 0;
            if(j1==j2)
                cur = mat[i][j1] + fun(i+1,j1+l,j2+k,r,c,dp,mat) ;     
            else
                cur =   mat[i][j1] + mat[i][j2] + fun(i+1,j1+l,j2+k,r,c,dp,mat) ;
            maxi = max(maxi,cur);
        }
    }

    return dp[i][j1][j2] = maxi ;
}


int maximumChocolates(int r, int c, vector<vector<int>> &mat) {

    // dp ( memoization   n*m*m *9 , n*m*m + stack( n-1) )

    // vector< vector< vector<int> > > dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    // return fun(0,0,c-1,r-1,c-1,dp,mat);





    // tabulation ( n*m*m *9 , n*m*m  )

    // vector< vector< vector<int> > > dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    // for(int j1=0;j1<c;j1++){
    //     for(int j2=0;j2<c;j2++){
    //         if(j1==j2)
    //             dp[r-1][j1][j2] = mat[r-1][j1];
    //         else 
    //             dp[r-1][j1][j2] = mat[r-1][j1]+mat[r-1][j2];
    //     }
    // }

    // for(int i=r-2;i>=0;i--){
    //     for(int j1=0;j1<c;j1++){
    //         for(int j2=0;j2<c;j2++){
                
    //             int maxi=0;
    //             for(int l=-1;l<=1;l++ ){
    //                 for(int k=-1;k<=1;k++ ){
    //                     if(j1+l>=0 && j1+l<c && j2+k>=0 && j2+k<c ){
    //                         if( j1==j2 )
    //                             maxi = max( maxi, mat[i][j1] + dp[i+1][j1+l][j2+k] );
    //                         else
    //                             maxi = max(maxi, mat[i][j1] + mat[i][j2] + dp[i+1][j1+l][j2+k] );
    //                     }
    //                 }
    //             }
    //             dp[i][j1][j2] = maxi;
            
    //         }
    //     }
    // }
    // return dp[0][0][c-1] ;






    // space optimization ( n*m*m *9 , m*m  )

    vector< vector<int> > next(c,vector<int>(c,-1));
    for(int j1=0;j1<c;j1++){
        for(int j2=0;j2<c;j2++){
            if(j1==j2)
                next[j1][j2] = mat[r-1][j1];
            else 
                next[j1][j2] = mat[r-1][j1]+mat[r-1][j2];
        }
    }

    for(int i=r-2;i>=0;i--){
        vector< vector<int> > cur(c,vector<int>(c,-1));

        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){        
                int maxi=0;
                for(int l=-1;l<=1;l++ ){
                    for(int k=-1;k<=1;k++ ){
                        if(j1+l>=0 && j1+l<c && j2+k>=0 && j2+k<c ){
                            if( j1==j2 )
                                maxi = max( maxi, mat[i][j1] + next[j1+l][j2+k] );
                            else
                                maxi = max(maxi, mat[i][j1] + mat[i][j2] + next[j1+l][j2+k] );
                        }
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        next = cur;
    }
    return next[0][c-1] ;

}



// n is row here , m is columns 

// Recursion :  3^(n*n ) , stack space ( n )
// memoization :  n*m*m*9 , n*m*m + stack( n ) 
// tabular : n*m*m , n*m*m  
// space optimization : n*m*m , m*m

