//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        //Solving this problem whith the  help of Moore Vooting Algoritm which will 
        //provide a candidate element which has more vote among all the element
        
        //Assuming our first array element is candidate element with one vote
        int res=0,count=1;
        for(int i=1;i<size;i++)
        {
            //if array element is same as previous array element then increase the vote by 
            //one
            if(a[res]==a[i])
            {
                count++;
            }
            //if array element is different then previous element then decrease the vote by 
            //one 
            else
            {
                count--;
            }
            //if there is no vote remain then make the current array element as candidate
            //start vooting for this candidate
            if(count==0)
            {
                res=i;
                count=1;
            }
        }
        //Now validate whether our candidate element is majority element of not
        count=0;
        for(int i=0;i<size;i++)
        {
            if(a[res]==a[i])
            {
                count++;
            }
        }
        if(count<=size/2)
        {
            return -1;
        }
        return a[res];
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends