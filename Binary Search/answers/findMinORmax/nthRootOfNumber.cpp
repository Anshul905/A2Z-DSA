int fun(int mid,int m , int n){
  long long ans = 1 ;
  for(int i=0;i<n;i++){
     ans *= mid ;
     if(ans>m)
       return 2;
  }
  if(ans==m) return 1;
  return 0;
}
int NthRoot(int n, int m) {

    // log(m)*log(m) but using pow method gives wrong ans sometime ( in case of overflow ) eg. pow(1e9,10) == 1e90 cant store 
    // int low=0,high=m;
    // while(low<=high){
    //     long long mid = low+(high-low)/2;
    //     long long sq = pow(mid,n) ; 
    //     if(sq==m)
    //       return mid;

    //     if( sq > m ){
    //         high = mid-1 ;
    //     }else{
    //         low = mid+1 ;
    //     }
    // }
    // return -1;



    // log(m)*n
    int low=0,high=m;
    while(low<=high){
        long long mid = low+(high-low)/2;
        long long sq = fun(mid,m,n) ; 
        if(sq==1)
          return mid;

        if( sq == 2 ){
            high = mid-1 ;
        }else{
            low = mid+1 ;
        }
    }
    return -1;

}


// take long long as it can overflow 
// lon(m)*log(m) but using pow method gives wrong ans sometime ( in case of overflow ) eg. pow(1e9,10) 
// so log(m)*n with our function and we break once the product > m , no overflow problem 

// i think we can also do it using binary exponential ... but i m not sure  
