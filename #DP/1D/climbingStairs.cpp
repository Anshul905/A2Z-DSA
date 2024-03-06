    int fun(int n,vector<int> &dp){
        if( n==0 || n==1 )
            return 1 ;
        if(dp[n]!=-1)
            return dp[n];
        return  dp[n] = fun(n-1,dp)+fun(n-2,dp);
    }
    int climbStairs(int n) {

        // dp ( memoization n,2*n )

        // vector<int> dp(n+1,-1);
        // return fun(n,dp);
        


        // dp ( tabulation n,n )

        // vector<int> dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++)
        //     dp[i]=dp[i-1]+dp[i-2];
        // return dp[n];


        // dp ( space optimize n,1 )

        int pre = 1 , pre2pre = 1 ;
        for(int i=2;i<=n;i++){
            int cur = pre+pre2pre;
            pre2pre = pre;
            pre = cur;
        }
        return pre;

    }
