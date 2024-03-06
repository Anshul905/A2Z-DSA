#include <bits/stdc++.h>
long fun(int ind , int buy , int n , long *prices, vector<vector<long>> &dp) {
    if(ind==n)
        return 0;
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];

    long profit=0;
    if(buy){
        profit = max( -prices[ind] + fun(ind+1,0,n,prices,dp) , 0 + fun(ind+1,1,n,prices,dp)   );
    }else{
        profit = max(  prices[ind] + fun(ind+1,1,n,prices,dp) , 0 + fun(ind+1,0,n,prices,dp)   );
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *prices, int n) {

// memoization :  n*2 , n*2 + stack 
// vector<vector<long>> dp(n,vector<long>(2,-1));
// return fun(0,1, n, prices,dp);



// tabulation :  n*2 , n*2  
// vector<vector<long>> dp(n+1,vector<long>(2,-1));
// dp[n] = {0,0};

// for(int ind=n-1;ind>=0;ind--){
//     for(int buy=0;buy<2;buy++){
//         long profit=0;
//         if(buy){
//             profit = max( -prices[ind]+dp[ind+1][0] , dp[ind+1][1]  );
//         }else{
//             profit = max( prices[ind]+dp[ind+1][1] , dp[ind+1][0]  );
//         }
//         dp[ind][buy] = profit ;
//     }
// }
// return  dp[0][1];



// space optimization :  n*2 , 2  
vector<long> next(2,0);
for(int ind=n-1;ind>=0;ind--){
    vector<long> cur(2,0);
    for(int buy=0;buy<2;buy++){
        long profit=0;
        if(buy){
            profit = max( -prices[ind]+next[0] , next[1]  );
        }else{
            profit = max( prices[ind]+next[1] , next[0]  );
        }
        cur[buy] = profit ;
    }
    next = cur ;
}
return  next[1];




// greedy
// if(n<=1)
//     return 0;
// long profit=0;
// long minSoFar=prices[0];

// for(int i=1;i<n;i++){
//     if( prices[i]<prices[i-1] ){
//         profit += (prices[i-1]-minSoFar);
//         minSoFar = prices[i];
//     }
// }
// profit += (prices[n-1]-minSoFar);
// return profit;


// greedy
//   if (n <= 1)
//     return 0;
//   long profit = 0;
//   for (int i = 1; i < n; i++) {
//     if (prices[i] > prices[i - 1]) {
//       profit += (prices[i] - prices[i - 1]);
//     }
//   }
//   return profit;



// greedy
// int s=0,b=0 ;
// long profit = 0 ;
// for(int i=1 ; i<n ; i++){
//     if(prices[i]>prices[i-1]){
//         s++ ;
//     }else{
//         profit += prices[s]-prices[b] ;
//         s = i ;
//         b = i ;  
//     }
// }  
// profit += prices[s]-prices[b] ;
// return profit ;    



}




// b-s ..... b-s...... no limit 

// memoization :  n*2 , n*2 + stack 
// tabulation :  n*2 , n*2  
// space optimization :  n*2 , 2*2
// greedy ( n,1 ) or ( n,2 )

