int fun(vector<int>& books , int pagesLimit){

    int student = 0;
    int curPages = 0;

    for(int i=0;i<books.size();i++){
        curPages += books[i];
        if( curPages > pagesLimit ){
             student++;
            curPages = books[i];
        }
    }
    student++;
    return student;
}

int findPages(vector<int>& arr, int n, int m) {

        if( n<m )
            return -1;

        int maxi_element = *max_element(arr.begin(),arr.end());
        int sum = accumulate(arr.begin(),arr.end(),0);
        int low = maxi_element , high = sum ;
        //low = maximum element is a book having max no. of pages , someone will have to take it , atleast this one so this much is for sure  
        // high is sum when m==1

        while( low<=high ){
            int  mid = low+(high-low)/2 ;
            int ret  = fun(arr, mid );

            // if its possible or ret<m means distributed to less students,, reduce the page limit 
            if( ret <= m )
                high =  mid-1;
            else 
                low = mid+1;
           
        }
        return low;

}

// TC : log( sum-maxi_element ) * n

// if books are supposed to be distributed amoung  5 student and even if you cant with above function 
// you wont return -1 , rather low will take less students wala answer  ( because now books are more than students for sure so it is possible to reduce the some students book  and give to another one who does not have ))