//{ Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    //Complete this function
    int digitalRoot(int n)
    {
        //if there will be single digit
        if(n<=9)
        {
            return n;
        }
        //getting total sum of digits
        n=digitSum(n);
        
        //check wheter n is single digit or not
        digitalRoot(n);
    }
    int digitSum(int n)
    {
        if(n<=9)
        {
            return n;
        }
        return (n%10)+digitSum(n/10);
    }
};

//{ Driver Code Starts.


int main() {
	int T;
	cin>>T;//taking testcases
	while(T--)
	{
	    int n;
	    cin>>n;//taking number n
	    
	    //calling digitalRoot() function
	    Solution obj;
	    cout<<obj.digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}
// } Driver Code Ends