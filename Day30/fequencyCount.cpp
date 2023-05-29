//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int N, int k) {
        // Solving this problem with the help hashing technique
       unordered_map<int, int> freqMap;
       
       
       // Count the frequency of each element in the array
       for (int i = 0; i < N; i++) {
        freqMap[arr[i]]++;
        }

        int count = 0;

        // Check which elements appear more than n/k times
        for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
            if (it->second > N/k) {
            count++;
          }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends