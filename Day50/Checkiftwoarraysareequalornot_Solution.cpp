//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// } Driver Code Ends
//User function template for C++

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //creating frequency array to store the occurence of element in array A
        unordered_map<int,int> freq;
        
        //Count the fequency of array A element 
        for(int i=0;i<N;i++){
            
            //if element is found first time then 
            if(freq.find(A[i])==freq.end()){
                freq[A[i]]=1;
            }
            //if element is already present then increase the frequency by one
            else{
                freq[A[i]]++;
            }
        }
        
        //Now math frequency array with array B 
        for(int i=0;i<N;i++){
            //if element is not found in frequency array it means arrays are not same
            if(freq.find(B[i])==freq.end()){
                return false;
            }
            //if element is found then the decrease the frequency by one 
            else{
                freq[B[i]]--;
                //after decreasing frequency check it is less then zero means both 
                //arrays have different different occurence of element so return false
                if(freq[B[i]]<0){
                    return false;
                }
            }
        }
        //if everything is ok then return both arrays are same array
        return true;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        Solution ob;
        cout << ob.check(arr,brr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends