//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    // The function should do the stated modifications in the given array arr[]
    // Do not return anything.
    
    // arr[]: Input Array
    // N: Size of the Array arr[]
    //Function to segregate 0s, 1s and 2s in sorted increasing order.
    void segragate012(int array[], int N)
    {
        // Solving this problem with the help of Dutch National Flag Algorithm
        int i=0,start=0,end=N-1;
        while(i<=end)
        {
            //if we found element less than a then swap it with start pointer
            if(array[i]==0)
            {
                swap(array[i],array[start]);
                ++i;
                ++start;
            }
            //if we found element higher than b then swap it with 
            else if(array[i]>1)
            {
                swap(array[i],array[end]);
                --end;
            }
            else{
                ++i;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        Solution ob;
        ob.segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}

// } Driver Code Ends