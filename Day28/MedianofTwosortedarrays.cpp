//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        // Solving with the help of Binary Search Algorithm by assuming two subparts of 
        //both arrays
        int begin=0;
        //taking smaller length of array length for end value
        int end=(n<=m)?n:m;
        
        //writing Binary Search Algo
        while(begin<=end)
        {
            //Calculating medium of first array
            int i1=begin+(end-begin)/2;
            //calulating medium of our second array using first array medium index
            int i2=((n+m+1)/2)-i1;
            
            //intializing min1 and max1 from first array
            int min1=(i1==n)?INT_MAX:arr[i1];
            int max1=(i1==0)?INT_MIN:arr[i1-1];
            
            //inializing min2 and max2 from second array
            int min2=(i2==m)?INT_MAX:brr[i2];
            int max2=(i2==0)?INT_MIN:brr[i2-1];
            
            //if left part of both array elements are smaller than all the elements present in 
            //rigth side of array then we get our median of both array
            if(max1<=min2 && max2<=min1)
            {
                if((n+m)%2==0)
                {
                    return (max(max1,max2)+min(min1,min2))/2;
                }
                else{
                    return max(max1,max2);
                }
            }
            //if element is smaller then move towards left side
            else if(max1>min2)
            {
                end=i1-1;
            }
            //if element is greater then move towards right side
            else
            {
                begin=i1+1;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}
// } Driver Code Ends