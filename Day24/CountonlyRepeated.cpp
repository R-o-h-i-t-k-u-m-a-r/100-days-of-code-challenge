//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<long, long> findRepeating(long *arr, int n){
        //Solving this problem with the help of Binary Search Algorithm
        pair<long,long> ans;
        //If array is consecutive sorted then we can find whether how many duplicates 
        //elements are there with the bleow calulation
        long repeat=n-(arr[n-1]-arr[0]);
        
        //if there are more than one repeated elements then
        if(repeat>1 && n>1)
        {
            //Writing Binary search algorithm
            int low=0,high=n-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                //if all elements are distinct up to the mid index of array 
                if(arr[mid]>=(mid+arr[0]))
                {
                    //Check for right half of array elements
                    low=mid+1;
                }
                else{
                    //Otherwise check for left half of array elements
                    high=mid-1;
                }
            }
            //When binary serach will be over we observe that we array of low index
            //element is of duplicate element in the array
            ans.first=arr[low];
            ans.second=repeat;
        }
        else{
            ans.first=-1;
            ans.second=-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    long arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<long, long> ans = obj.findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}
// } Driver Code Ends