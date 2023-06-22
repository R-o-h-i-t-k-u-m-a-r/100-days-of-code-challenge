//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Solving this problem with the help of HashSet and Prefix sum 
        unordered_set<int> hashSet;
        int prefix_Sum=0;
        
        for(int i=0;i<n;i++){
            
            //Store subarray element sum as a prefix sum
            prefix_Sum+=arr[i];
            
            //If prefix sum is equal to zero then return true
            if(prefix_Sum==0){
                return true;
            }
            //If we have already a prefix sum in hash set which is equal to current 
            //prefix sum then there difference will be zero it means there should be 
            //subarray present with 0 sum.
            if(hashSet.find(prefix_Sum)!=hashSet.end()){
                return true;
            }
            //other there is no prefix sum fond earlier in hash set then insert it 
            //for further reference
            else{
                hashSet.insert(prefix_Sum);
            }
        }

        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends