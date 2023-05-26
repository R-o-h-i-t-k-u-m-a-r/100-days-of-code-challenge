//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //Solving this problem with the help of Binary Search Algorithm
        
        //If there are less number of pages than total number of students
        if(N<M)
        {
            return -1;
        }
        //Finding sum of array elements and maximum of array elements
        int sum=0,mx=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            mx=max(mx,A[i]);
        }
        //Implementing Binary Search Algorithm
        //Allocating maximum pages to low index and total sum to the high index;
        int low=mx,high=sum,res=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            //validating either mid number of pages can be distributed among studends or not
            if(isFessible(A,N,M,mid))
            {
                //If mid is fessible solution then moving left side so that we can 
                //get more number of minimum pages that can be fessible solution
                res=mid;
                high=mid-1;
            }
            else
            {
                //if mid is not fessible solution then we need to increase number of 
                //pages so we move right side
                low=mid+1;
            }
        }
        return res;
    }
    
    bool isFessible(int arr[],int n,int k,int ans)
    {
        //Initally assuming we only have requirement of one student 
        int req=1,sum=0;
        for(int i=0;i<n;i++)
        {
            //if total number of pages is greater than allocating pages
            if(sum+arr[i]>ans)
            {
                //increase number of student by one
                req++;
                //assign new page to new student
                sum=arr[i];
            }
            else
            {
                //if total number of pages is less than or equal to allocating page
                //increament the sum by next array element
                sum+=arr[i];
            }
        }
        return (req<=k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends