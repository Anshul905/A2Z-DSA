int lcs(string &text1, string &text2){
        
        // int m=text1.size();
        // int n=text2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return fun_shifted_index(m,n,text1,text2,dp);




        // int m=text1.size();
        // int n=text2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0)); 
        // //base case is already have 0
        // for(int ind1=1;ind1<m+1;ind1++){
        //     for(int ind2=1;ind2<n+1;ind2++){
        //         int cur = 0 ;
        //         if(text1[ind1-1]==text2[ind2-1])
        //             cur = 1+dp[ind1-1][ind2-1];
        //         else
        //             cur = 0;
        //         dp[ind1][ind2] = cur;
        //     }
        // }
        // int ans=0;
        // for(int ind1=1;ind1<m+1;ind1++){
        //     for (int ind2 = 1; ind2 < n + 1; ind2++) {
        //         ans = max(ans,dp[ind1][ind2]);
        //     }
        // }
        // return ans;        




        int m=text1.size();
        int n=text2.size();
        vector<int> prev(n+1,0); 
        int ans=0;
        for(int ind1=1;ind1<m+1;ind1++){
	        vector<int> current(n+1,0); 
            for(int ind2=1;ind2<n+1;ind2++){
                int cur = 0 ;
                if(text1[ind1-1]==text2[ind2-1])
                    cur = 1+prev[ind2-1];
                else
                    cur = 0;
                current[ind2] = cur;
                ans=max(ans,current[ind2]);
            }
			prev = current;
        }
        return ans;        


}


// have bot written recusrive/memoiation  solution 
// Recursion : [ 3^n , stack ] some 3 variable .... 
// memoization : [ 3d dp i think but not sure  ] 


// tabulation :  m*n , m*n  
// space optimization :  m*n , n


// ans = maximum from the lcs table ( put 0 when no match on tabulation code )

