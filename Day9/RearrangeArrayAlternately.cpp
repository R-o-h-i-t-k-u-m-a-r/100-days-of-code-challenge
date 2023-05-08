//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	/* Solving this problem with the help of equation of
    	Dividend=Divisor*Quotient+Remainder*/
    	
    	//Initializing Divisor 
    	long long Divisor=arr[n-1]+1;
    	int i=0,j=n-1;
    	
    	//indexes for Maximum elements and Minimum elements respectively
    	int i_index=1,j_index=0;
    	
    	//For array having only length one then
    	if(n==1)
    	{
    	    return;
    	}
    	//For array having only length two then
    	else if(n==2)
    	{
    	    int temp=arr[0];
    	    arr[0]=arr[1];
    	    arr[1]=temp;
    	}
    	//For array having more than length two then
    	else
    	{
    	while(i<=j)
    	{
    	    if(j_index<n)
    	    {
    	    arr[j_index]=Divisor*(arr[j]%Divisor)+arr[j_index];    
    	    }
    	    if(i_index<n)
    	    {
    	     arr[i_index]=Divisor*(arr[i]%Divisor)+arr[i_index];   
    	    }
    	    
    	    i++;
    	    j--;
    	    j_index+=2;
    	    i_index+=2;
    	}
    	
    	//Retriving original elements in the array with the help of Divisor
    	for(int i=0;i<n;i++)
    	{
    	    arr[i]=arr[i]/Divisor;
    	}
    	
    	}
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends