//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // Function to count number of Ones
    // arr: input array 
    // N: size of input array
    int countOnes(int arr[], int N)
    {
        //Solving this problem with the help of Binary Search Algorithm
        
        int low = 0, high = N - 1;
        int mid = high - (high - low) / 2;

	    // binary search to count 1s
	    while (low <= high) {
	        mid = high - (high - low) / 2;

		    // check if mid is 1
		    if (arr[mid] == 1 && mid + 1 < N && arr[mid + 1] == 1) {
		        low = mid + 1;
		        
		    }

		    // if mid is not 0, then iterate for lower half
		   else if (arr[mid] == 0) {
		       high = mid - 1;
		       
		   }

		   // else iterate for upper half
		   else if (arr[mid] == 1 && ((mid + 1 < N && arr[mid + 1] == 0) || (mid == N - 1))) {
			return mid + 1;
		       
		   }
	        
	    }
	    
	    return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends