string fun_shifted_index(int ind1, int ind2, string s1, string s2,
		vector<vector<string>>& dp) {
	if (ind1 == 0 || ind2 == 0)
		return "";
	if (dp[ind1][ind2] != "")
		return dp[ind1][ind2];

	string cur = "";
	if (s1[ind1-1] == s2[ind2-1])
		cur = s1[ind1-1] + fun_shifted_index(ind1 - 1, ind2 - 1, s1, s2, dp);
	else {
		cur = max(fun_shifted_index(ind1 - 1, ind2, s1, s2, dp),
					fun_shifted_index(ind1, ind2 - 1, s1, s2, dp));
	}
	return dp[ind1][ind2] = cur;
}

string findLCS(int n, int m,string &s1, string &s2){
	
        // vector<vector<string>> dp(n+1,vector<string>(m+1,""));
        // string ans = fun_shifted_index(n,m,s1,s2,dp);
		// reverse(ans.begin(),ans.end());


        // vector<vector<string>> dp(n+1,vector<string>(m+1,""));
        // for(int ind1=1;ind1<n+1;ind1++){
        //     for(int ind2=1;ind2<m+1;ind2++){
        //         string cur = "" ;
        //         if(s1[ind1-1]==s2[ind2-1])
        //             cur = dp[ind1-1][ind2-1] + s1[ind1-1];
        //         else
        //             cur = dp[ind1-1][ind2].size()>dp[ind1][ind2-1].size() ? dp[ind1-1][ind2] : dp[ind1][ind2-1]  ;
        //         dp[ind1][ind2] = cur;
        //     }
        // }
		// return dp[n][m];



        // vector<string> prev(m+1,""); 
        // for(int ind1=1;ind1<n+1;ind1++){
	    //     vector<string> current(m+1,""); 
        //     for(int ind2=1;ind2<m+1;ind2++){
        //         string cur = "" ;
        //         if(s1[ind1-1]==s2[ind2-1])
        //             cur = prev[ind2-1]+s1[ind1-1];
        //         else
        //             cur =  prev[ind2].size()>current[ind2-1].size() ? prev[ind2] : current[ind2-1] ;
        //         current[ind2] = cur;
        //     }
		// 	prev = current;
        // }
        // return prev[n];        




        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int ind1=1;ind1<n+1;ind1++){
            for(int ind2=1;ind2<m+1;ind2++){
                int cur = 0 ;
                if(s1[ind1-1]==s2[ind2-1])
                    cur = 1+dp[ind1-1][ind2-1];
                else
                    cur = max( dp[ind1-1][ind2] , dp[ind1][ind2-1]);
                dp[ind1][ind2] = cur;
            }
        }
		int len = dp[n][m];
		int index=len-1;
		
		string ans(len,'$');

		int i=n;
		int j=m;
		while(i>0 && j>0){
			if(s1[i-1]==s2[j-1]){
				ans[index--]=s1[i-1];
				i--;
				j--;
			}else{
				if(dp[i][j-1]>dp[i-1][j])
					j--;
				else
					i--;
			}
		}
		return ans;
}

// Recursion : 2^n , stack 
// memoization :  m*n , m*n + stack 
// tabulation :  m*n , m*n  
// space optimization :  m*n , n


// use same approach as lcs --> get table filled --> use while loop to get the string 
// same 3 method --> string inplace of int ( 0 -> "" ) 