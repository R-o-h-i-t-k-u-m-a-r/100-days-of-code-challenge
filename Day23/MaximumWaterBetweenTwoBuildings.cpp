//{ Driver Code Starts
//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) 
    { 
        //Solving with help of two pointer technique algorithm
        int water=0,i=0,j=n-1;
        while(i<j)
        {
            //if left building is smaller than rightmost building then move left by one
            if(height[i]<height[j])
            {
                water=max(water,(j-i-1)*height[i]);
                i++;
            }
            //if right building is smaller than leftmost building then move right by one
            else if(height[j]<height[i])
            {
                water=max(water,(j-i-1)*height[j]);
                j--;
            }
            else{
                if both are same move both side by one
                water=max(water,(j-i-1)*height[i]);
                i++;
                j--;
            }
        }
        return water;
    } 
};



//{ Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }

	 
} 


// } Driver Code Ends