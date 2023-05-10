//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        //Solving this problme with the help of Kadane's Algorithm
        if(num==1)
        {
            return arr[0];
        }
        //Step 1: finding Max Subarray sum of normal array using Kadane's Algorithm
        int max1=Kadane(arr,num);
        
        //if our max1 is -ve means all the elements are -ve so no need to check more
        if(max1<0)
        {
            return max1;
        }
        
        //Step 2:Finding total sum of elements of the array and inverting the elements sign
        int arr_sum=0;
        for(int i=0;i<num;i++)
        {
            arr_sum+=arr[i];
            arr[i]=-arr[i];
        }
        
        //Step 3:Now Finding Max subarray sum again with the help of Kadane's Algorithm
        int max2=Kadane(arr,num);
        
        //Step 4:As we have inverted our array elements sign so finding maximum subarray
        //sum will give us minimum subarray sum so for gettting maximum subarray sum 
        //we need to add minimum value to our arr_sum as minimum value will always be -ve.
        max2=arr_sum+max2;
        
        //Now compare max1 means normal array subaraay sum and max2 means circular 
        //subarray sum
        
        return max(max1,max2);
    }
    
    int Kadane(int arr[],int n)
    {
        int glo_max=arr[0];
        int curr_max=arr[0];
        for(int i=1;i<n;i++)
        {
            curr_max=max(arr[i],arr[i]+curr_max);
            glo_max=max(curr_max,glo_max);
        }
        
        return glo_max;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends