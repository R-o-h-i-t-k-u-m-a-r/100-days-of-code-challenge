//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
    //when array is not rotated at all, we return first element.
    if (high < low)  
    return arr[0];
    
    //when both pointers become same, we return element at that pointer.
    if (high == low) return arr[low];
    

    int mid = low + (high - low)/2; 
    
    //if element at mid+1 is less than element at mid, we return 
    //element at mid+1 as it is minimum in the array.
    if (mid < high && arr[mid+1] < arr[mid])
       return arr[mid+1];
       
    //if element at mid is less than element at mid-1, we return 
    //element at mid as it is minimum in the array.
    if (mid > low && arr[mid] < arr[mid - 1])
       return arr[mid];
       
    //if element at high is greater than element at mid, the minimum element is
    //present in left half so calling function recursively for the left half.
    if (arr[high] > arr[mid])
       return minNumber(arr, low, mid-1);
       
    //else the minimum element is present in right half so calling
    //function recursively for right half.
    return minNumber(arr, mid+1, high);
        
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends