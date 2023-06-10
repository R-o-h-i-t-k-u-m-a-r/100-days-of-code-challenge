//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //First sort the  array if array is unsorted 
        sort(arr,arr+n);
        
        //check for each element up to n-2 for finding triplet sum
        for(int i=0;i<n-2;i++)
        {
            //Now check for other two elements for getting triplet sum of each element
            if(isPair(arr,i+1,n,arr[i]))
            {
                return true;
            }
        }
        return false;
    }
    //Finding Pair sum with the help of Two Pointer Technique in sorted array
    bool isPair(int arr[],int start,int n,int temp)
    {
        int i=start,j=n-1;
        while(i<j)
        {
            int ans=temp+arr[i]+arr[j];
            if(ans==0)
            {
                return true;
            }
            else if(ans<0)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends