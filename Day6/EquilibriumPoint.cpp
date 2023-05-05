//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        
        /*Soving this problem with the help of Prefix Sum Technique for O(1)
        Auxiliary space.*/
        
        //if array has only one element then
        if(n==1)
        {
            return 1;
        }
        
        //Finding Prefix Sum to get sum of arrays
        long long ps=0;
        for(int i=0;i<n;i++)
        {
            ps+=a[i];
        }
        
        //Initiallizing Suffix Sum as 0 for first element of array
        long long ss=0;
        
        for(int i=0;i<n;i++)
        {
            //subtracting Prefix sum to element a[i] so that we can get total sum of 
            //elemens after a[i] elements
            ps-=a[i];
            
            //if return index if element after a[i] and before a[i] is equal
            if(ps==ss)
            {
                return i+1;
            }
            
            //Otherwise increment ss by element a[i] because our ps has already been 
            //subtracted by element a[i]
            ss+=a[i];
        }
        
        //if not found return -1
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends