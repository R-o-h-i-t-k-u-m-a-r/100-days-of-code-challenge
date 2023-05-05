//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        //Creating LeftMax array to store maximum element before each element of array
        int lMax[n];
        lMax[0]=arr[0];
        
        for(int i=1;i<n;i++)
        {
            lMax[i]=max(lMax[i-1],arr[i]);
        }
        
        //Creating RightMax array to store maximum element after each element of array
        int rMax[n];
        rMax[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            rMax[i]=max(rMax[i+1],arr[i]);
        }
        
        long long  maxWater=0;
        //Storing all water amount 
        for(int i=1;i<n-1;i++)
        {
            int bar=min(lMax[i],rMax[i]);
            if(bar>arr[i])
            {
                maxWater+=bar-arr[i];
            }
            //maxWater+=min(lMax[i],rMax[i])-arr[i];
        }
        
        return maxWater;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends