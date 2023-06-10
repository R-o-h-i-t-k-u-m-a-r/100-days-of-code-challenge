//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    //Function to find next gap.
    int nextGap(int gap) 
    { 
        //It returns the ceil value of gap/2 or 0 if gap is 1.
    	if (gap <= 1) 
    		return 0; 
    	return (gap / 2) + (gap % 2); 
    } 
    
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    { 
        //Here we will use Gap Technique of enhanced Insertion sort i.e Shell Sort 
        //Algorithm to sort the both arr1 and arr2 together
    	int i, j, gap = n + m; 
    	
    	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    	{ 
    	    //Comparing elements in the first array itself with difference in 
    	    //index equal to the value of gap. 
    		for (i = 0; i + gap < n; i++) 
    		    //If element at ith index is greater than element at
    		    //(i+gap)th index, we swap them. 
    			if (arr1[i] > arr1[i + gap]) 
    				swap(arr1[i], arr1[i + gap]); 
    
    		//Now comparing elements in both arrays with help of two pointers.
    		//The loop stops whenever any pointer exceeds the size of its array.
    		for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++)
    		    //If element in the first array is greater than element in
    		    //second array, we swap them. 
    			if (arr1[i] > arr2[j]) 
    				swap(arr1[i], arr2[j]); 
            
    		if (j < m) 
    		{ 
    			//At last, comparing elements in the second array itself with 
                //difference in index equal to the value of gap.
    			for (j = 0; j + gap < m; j++) 
    			    //If element at jth index is greater than element at
    		        //(j+gap)th index, we swap them. 
    				if (arr2[j] > arr2[j + gap]) 
    					swap(arr2[j], arr2[j + gap]); 
    		} 
    	} 
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends