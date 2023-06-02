//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
       //Initializing two variable for storing previous incresing consecutive building
       //steps and current increasing cosecutive building steps
       int final_step=0;
       int curr_step=0;
       //Moving from initial building to last building
       for(int i=0;i<N-1;i++)
       {
           //If first building is smaller than next building height
           if(A[i]<A[i+1])
           {
               //then increase the current steps by one
               curr_step++;
           }
           //otherwise
           else{
               //reset the current steps to zero
               curr_step=0;
           }
           //finally taking the maximum steps covered from start to end building
           final_step=max(final_step,curr_step);
       }
       
       return final_step;
    }
};

//{ Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends