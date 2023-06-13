//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the kth smallest element in the array.
    int kthSmallest(int arr[], int n, int k)
    {
        //Solving this problem with the help of Lomuto Partion of Quick sort
        //This techinque is also know as Quick Select Algorithm
        
        int low=0,high=n-1;
        while(low<=high)
        {
            //Getting index of pivot element
            int index=partition(arr,low,high);
            
            //if index is equal to k-1 it means we found our element because pivot element
            //ensure its appropriate position
            if(index==k-1)
            {
                return arr[index];
            }
            
            //if pivot element index is less then k-1 it means there can not smaller element
            //before pivot element so we need to move right side for getting higher element
            else if(index<k-1)
            {
                low=index+1;
            }
            //Otherwise move left side of pivot element 
            else{
                high=index-1;
            }
        }
        
        return -1;
    }
    
    //Implementing Lomuto Partition
    int partition (int arr[], int low, int high)
    {
       int i=-1;
       for(int j=0;j<high;j++)
       {
           //If there is element which is smaller than pivot element then shift if to left
           if(arr[j]<=arr[high])
           {
               i=i+1;
               swap(arr[i],arr[j]);
           }
       }
       //After shifting all smaller elements to the left side then swap pivot element
       //with next to right most smallert element index
       swap(arr[i+1],arr[high]);
       
       //Finally return of pivot element index
       return i+1;
    }
};


//{ Driver Code Starts.
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    Solution ob;
	    cout << ob.kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}
// } Driver Code Ends