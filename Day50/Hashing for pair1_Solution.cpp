//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int N, int sum);

// } Driver Code Ends
// User function Template for C++

// You need to complete this function.
// Function to check if there is a pair with the given sum in the array.
int sumExists(int arr[], int N, int sum) {
    // Solving this problem with the help of HashMap for accessing element in O(1) time
    unordered_map<int,int> map;
    
    //Iterating over the array element to check if there is a pair of sum or not 
    for(int i=0;i<N;i++){
        
        //if array element is greater than sum then no need to check with other element
        if(arr[i]>sum){
            continue;
        }
        //if we found element in hashmap that make sum by adding current element then
        //return 1
         else if(map.find(abs(sum-arr[i]))!=map.end()){
                return 1;
         }
         //otherwise simply insert element into hashmap for making pair with other elments
         else{
             map[arr[i]]=arr[i];
         }
    }
    //if there is now pair sum element is found then return 0
    return 0;
}

//{ Driver Code Starts.

int main() {

    int testcases;
    cin >> testcases;
    while (testcases--) {
        int N;
        cin >> N;

        int arr[N];

        for (int i = 0; i < N; i++) cin >> arr[i];
        int sum;
        cin >> sum;

        cout << sumExists(arr, N, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends