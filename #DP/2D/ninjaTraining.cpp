int fun(int day,int last,vector<vector<int>> &points , vector<vector<int>> &dp){

    if(day==0){
        int maxi = 0;
        for(int task=0;task<=2;task++){
            if(task!=last)
                maxi = max(maxi,points[0][task]);
        }
        return dp[0][last] = maxi;
    }
    
    if(dp[day][last]!=-1)
        return dp[day][last];

    int maxi = 0;
    for(int task=0;task<=2;task++){
        if(task!=last)
            maxi = max(maxi,points[day][task]+fun(day-1,task,points,dp));
    }

    return dp[day][last] = maxi ;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // f(n,i) or dp[n][i] --> maximum points on nth day by not selecting ith task on nth day  


    // dp ( memoization (n*4)*3 ,n*4 + stack )

    // vector<vector<int>> dp(n,vector<int>(4,-1));
    // return fun(n-1,3,points,dp);




    // tabulation ( (n*4)*3 ,n*4  )

    // vector<vector<int>> dp(n,vector<int>(4,0));
    // dp[0] = { max(points[0][1],points[0][2]) , max(points[0][0],points[0][2]), max(points[0][0],points[0][1]) , max( points[0][0],max(points[0][1],points[0][2]) )  };

    // for(int day=1;day<n;day++){
    //     for(int last=0;last<=3;last++){
    //         int maxi = 0 ;
    //         for(int task=0;task<=2;task++){
    //             if(task!=last)
    //                 maxi = max(maxi,points[day][task]+dp[day-1][task]);
    //         }
    //         dp[day][last] = maxi;
    //     }
    // }
    // return dp[n-1][3];




    // space optimization( (n*4)*3 , 4 ~~ task+1 )

    vector<int> dp = { max(points[0][1],points[0][2]) , max(points[0][0],points[0][2]), max(points[0][0],points[0][1]) , max( points[0][0],max(points[0][1],points[0][2]) )  };
    vector<int> temp(4,0)  ;
    for(int day=1;day<n;day++){
        for(int last=0;last<=3;last++){
            int maxi = 0 ;
            for(int task=0;task<=2;task++){
                if(task!=last)
                    maxi = max(maxi,points[day][task]+dp[task]);
            }
            temp[last] = maxi;
        }
        dp = temp;
    }
    return dp[3];

}



// f(n,i) or dp[n][i] --> maximum points on nth day by not selecting ith task on nth day  

// recursion (3^(n*4),stack)-> memoization( (n*4)*3 ,n*4 + stack )-> tabular( (n*4)*3 ,n*4 )-> space optimization( (n*4)*3 , 4 ) 
