public:
    bool isLucky(int n) {
        // Solving this problem with the help of Recursion
        int count=2;
        
        return checkLucky(n,count);
        
    }
    
    bool checkLucky(int n,int count)
    {
        //Base case if couting would be higher than total elments then last elements will
        //be our lucky number
        if(n<count)
        {
            return true;
        }
        //if last number is divisible then that will not be lucky number
        if(n%count==0)
        {
            return false;
        }
        
        //getting total number of elements after deleting by count number
        n=n-n/count;
        
        //increasing count by 1 in each function call
        count++;
        //calling our function after reducing total elements and increasing count
        return checkLucky(n,count);
        
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends