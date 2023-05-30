//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
// Function to find element in sorted array

int leftIndex(int N, int arr[], int X){
    
    //Solving this problem with the help of Binary Search Algorithm
    int low=0,high=N-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        //if we get our element
        if(arr[mid]==X)
        {
            //and it has valid previous index to check  
            if((mid-1)>=0)
            {
                //and element is similar to its valid previous element
               if(arr[mid-1]==X)
               {
                   //then move towards left half of array
                   high=mid-1;
               }
               //if element is not same to its previous element then return the index
               else{
                   return mid;
               }
            }
            //if element is already  in 0th position then no need to check further
            else{
                return mid;
            }
        }
        else if(arr[mid]>X)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
    
}




//{ Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}
// } Driver Code Ends