//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Solving this problem with the Binary Search Algorithm  
        long long low=1,high=x,ans=-1;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long midSq=mid*mid;
            if(midSq==x)
            {
                return mid;
            }
            else if(midSq>x)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends