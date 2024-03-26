#include <bits/stdc++.h>
int noOfGasStationRequired(vector<int> &arr, double maxDis){
	int cnt=0;
	for(int i=0;i<arr.size()-1;i++){
		double diff = (double)(arr[i+1]-arr[i]);
		int gs = diff/maxDis;
		if( gs*maxDis == arr[i+1]-arr[i] )
			gs--;
		cnt += gs;
	}
	return cnt;
}


double minimiseMaxDistance(vector<int> &arr, int k){

	// Brute force : ( k*n + n , n );
	// int n = arr.size();
	// vector<int> howMany(n-1,0);
	// for(int i=1; i<=k; i++){
	// 	int bestPlace=-1;
	// 	double maxi=-1;
	// 	for(int j=0; j<n-1; j++){
	// 		double diff = (double)(arr[j+1]-arr[j]);
	// 		double noOfStation = (double)howMany[j]+1 ;
	// 		double secLength = diff/noOfStation;

	// 		if( secLength>maxi ){
	// 			maxi = secLength;
	// 			bestPlace = j;
	// 		}
	// 	}
	// 	howMany[bestPlace]++;
	// }
	// double ans=-1;
	// for(int j=0; j<n-1; j++){
	// 	double a = (double)(arr[j+1]-arr[j]);
	// 	double b = (double)howMany[j]+1 ;
	// 	double secLength = a/b;
	// 	ans = max(ans,secLength);
	// }
	// return ans;



	// Using heap : (  (n-1)*log(n-1) [push in queue] + k*log(n-1) [for all k] , n-1 ) ~~  ( klogn, n) ;
	// int n = arr.size();
	// vector<int> howMany(n-1,0);
	// priority_queue<pair<double,int>> pq;
	// for(int i=0;i<n-1;i++)
    //       pq.push({arr[i + 1] - arr[i], i});

    //     for(int i=1; i<=k; i++){	
	// 		double bestPlace = (double)pq.top().second;
	// 		pq.pop();
	// 		howMany[bestPlace]++;
	// 		double totalDiff = (double)arr[bestPlace+1]-arr[bestPlace];
	// 		double noOfStation = (double)howMany[bestPlace]+1;
	// 		double secLength = totalDiff/noOfStation;

	// 		pq.push({secLength,bestPlace});			
	// 	}
	// 	return pq.top().first;




		// Binary search - ( n + n*log(range) , 1 ) == ( nlog(range), 1 )
		double low = 0 ;
		double high = 0 ;
		for(int i=0;i<arr.size()-1;i++)
			high = max( high , (double)arr[i + 1] - arr[i] );		

		double diff = 1e-6;
		double ans = high;
		while( high-low > diff ){
				double mid = low+(high-low)/2.0;
				int cnt =  noOfGasStationRequired(arr,mid);
				if( cnt > k )
					low = mid;
				else{
					ans = mid;
					high = mid;
				}
		}
		return ans;
}


// Brute force : k*n + n 
// // take one array presenting no. of newly added station between previously existing stations 
// for each k ( 1 to k )
// 	// find the best place it can fit into ,fin the gap with the greater diff so that you can put it between them
// 	maxi =  -1 , bestPlace = -1;
// 	for each place	( i to n-2 ) 
// 		diff = ;
// 		secLen = cur[i+1]-cur[i]/( howMany[i]+1 );
// 		if( secLen>maxi )
// 			maxi=secLen,bestPlace=i;
// 	howMany[bestPlace]++;


// optimise it -- heap ( nlogn+ klogn , n)
// we are taking o(n) ( inner loop ) for find the bestPlace  [  ]
// eg : 1 13 17 23 , k = 5 
// 12 4 6 
// top -> 12 , howMany -> ( 1 0 0 )
// 6 4 6
// top -> 6 , howMany -> ( 2 0 0 )
// 4 4 6
// top -> 6 , howMany -> ( 2 0 1)
// 4 4 3
// top -> 4  , howMany -> (3 0 1 )
// 3 4 3
// top -> 4  , howMany -> (3 1 1 )
// 3 2 3 


// eg : 1 2 3 4 5 , k=4 
// 1 1 1 1 
// top -> 1 , howMany -> ( 1 0 0 0 )
// 0.5 1 1 1 
// top -> 1 , howMany -> ( 1 1 0 0 )
// 0.5 0.5 1 1 
// top -> 1 , howMany -> ( 1 1 1 0 )
// 0.5 0.5 0.5 1 
// top -> 1 , howMany -> ( 1 1 1 1 )
// 0.5 0.5 0.5 0.5





// Binary search - ( n + n*log(range) , 1 ) == ( nlog(range), 1 )
// normally binary search structure wont work here 
// while(l<=h){
// 	.......
// 	l = m+1 ;
// 	.......
// 	h=m-1;
// 	.......
// }
// but 
// while( h-l > 1e-6 ){
// 	.......
// 	l = m ;
// 	.......
// 	h=m;
// 	.......	
// }


// 1 2 3 4 5 
// between 1 and 2 
// 0   0.1  0.3   0.5   0.7   1
// 0->infinite requirement ( no )
// 0.1 -> 9+9+9+9 = 36>k
// 0.4 -> 2+2+2+2 = 8 >k
// 0.5 -> 1+1+1+1 = 4 ( yes)
// answer is between 0.4 and 0.5 ( both included)
// but here for any mid less than 0.5 , you will get 8 which is greater than k , so answer is 0.5

// less mid = more requirement so move to right side --> low = mid 
// if at any mid, requirement <= k ( this can be answer but look for minimum one so move left , high=mid)




