//{ Driver Code Starts
//Initial Template for C++
#include<iostream> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Complete this function
    //Function to find the length of longest subarray of even and odd numbers.
    int maxEvenOdd(int arr[], int n) 
    { 
       //This problem is also based on Kadane's Algorithm Technique
       int ans=0;
       int cur_len=1;
       for(int i=1;i<n;i++)
       {
           //validatin for even odd pair of elements
           if(arr[i-1]%2==0 && arr[i]%2==1)
          {
              
              cur_len++;
              ans=max(ans,cur_len);
          }
          //validating for odd even of elements
           else if(arr[i-1]%2==1 && arr[i]%2==0)
          {
              cur_len++;
              ans=max(ans,cur_len);
           }
          else{
              cur_len=1;
            }
        }

        if(ans!=0)
          {
            return ans;
         }
  return 1;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int testcases;
    //testcases
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        //size of array
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        //inserting elements in the array
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        //calling function
        cout  << ob.maxEvenOdd(arr, sizeOfArray)<<endl; 
    }
   return 0; 
} 

// } Driver Code Ends