//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to find minimum difference between any pair of elements in an array.
    int MinimumDifference(int arr[], int n)
    {
        //Initializg ans variable with possible maximum integer
        int ans=INT_MAX;
        
        //sort the array
        sort(arr,arr+n);
        for(int i=1;i<n;i++)
        {
            int temp=abs(arr[i]-arr[i-1]);
            ans=min(ans,temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n]; 
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int diff = ob.MinimumDifference(arr, n);
	    cout << diff << endl;
	}
	return 0;
}
// } Driver Code Ends