//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        int lmin[N],rmax[N];
        lmin[0]=A[0];
        rmax[N-1]=A[N-1];
        
        for(int i=1;i<N;i++)
        {
            lmin[i]=min(lmin[i-1],A[i]);
        }
        
        for(int i=N-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],A[i]);
        }
        
        int mx=-1;
        int i=0,j=0;
        while(i<N && j<N)
        {
            if(lmin[i]<=rmax[j])
            {
                mx=max(mx,j-i);
                j++;
            }
            else
            i++;
        }
        
        return mx;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends