//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Sorting both arrival time and departure time
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	//Now with the help of Merge Procedure of Merge Sort finding how much trains
    	//can arrive together without having departure and to avoid that collions we 
    	//will need that number of extra platforms.
    	int i=1,j=0;
    	
    	//Assuming we have initially only one platform for arrival and departure trains
    	int res=1,curr=1;
    	
    	//Implenting merge procedure
    	while(i<n && j<n)
    	{
    	    //if we found train arrival time is less than or equal to other train departure
    	    //time then train will absoulity enter at station
    	    if(arr[i]<=dep[j])
    	    {
    	        //store the number of all incoming trains 
    	        curr++;
    	        i++;
    	    }
    	    //other wise train will leave from station
    	    else{
    	        curr--;
    	        j++;
    	    }
    	    res=max(res,curr);
    	}
    	
    	return res;
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
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends