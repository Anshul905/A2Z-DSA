int fun(vector<int>& boards , int boardPaintingLimit){

    int painter = 0;
    int curBoardPainted = 0;

    for(int i=0;i<boards.size();i++){
        curBoardPainted += boards[i];
        if( curBoardPainted > boardPaintingLimit ){
             painter++;
            curBoardPainted = boards[i];
        }
    }
    painter++;
    return painter;
}
int findLargestMinDistance(vector<int> &boards, int k)
{

        int n = boards.size();
        if( n<k )
            return -1;

        int maxi_element = *max_element(boards.begin(),boards.end());
        int sum = accumulate(boards.begin(),boards.end(),0);
        int low = maxi_element , high = sum ;
        //low = maximum element is a painter having max board  , someone will have to take it , atleast this one so this much is for sure  
        // high is sum when k==1

        while( low<=high ){
            int  mid = low+(high-low)/2 ;
            int ret  = fun(boards, mid );

            // if its possible or ret<m means distributed to less painters,, reduce the painter's total board 
            if( ret <= k )
                high =  mid-1;
            else 
                low = mid+1;
           
        }
        return low;

}

// TC : log( sum-maxi_element ) * n

// if boards  are supposed to be distributed amoung  5 painters and even if you cant do it with above function 
// you wont return -1 , rather low will take less painters wala answer  ( because now boards are more than painters for sure so it is possible to reduce the some painters board  and give to another one who does not have )