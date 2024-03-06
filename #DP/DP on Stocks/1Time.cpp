#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int profit=0;
    int minSoFar = prices[0];
    
    for(int i=1;i<prices.size();i++){
        profit = max( profit,prices[i]-minSoFar);
        minSoFar = min(minSoFar,prices[i]);
    }
    
    return profit;
}

// n, 1 