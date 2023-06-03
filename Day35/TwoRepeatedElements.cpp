//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        //vector that will store repeated elements
        vector<int> v;
        for(int i=0;i<N+2;i++)
        {
            //checking if array element of index first visited then mark with negative 
            if(arr[abs(arr[i])]>0)
            {
                arr[abs(arr[i])]=-arr[abs(arr[i])];
            }
            //if it is visited and found negative then it means array element has already
            //been occured before so store this element
            else{
                v.push_back(abs(arr[i]));
            }
        }
        //return the vector with repated elements 
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends