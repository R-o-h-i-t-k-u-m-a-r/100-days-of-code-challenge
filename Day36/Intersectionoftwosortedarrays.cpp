//{ Driver Code Starts
// C++ program to find union of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    //Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(int arr1[], int arr2[], int N, int M) 
    { 
        //Solving this problem with the help of Merge algorithm of Merge Sort
        int i=0,j=0;
        vector<int> v;
        //implementing Merge algorithm
        while(i<N && j<M)
        {
            //If we found element in the first has duplicate element then we will left 
            //that duplicate element and move further
            if(i>0 && arr1[i]==arr1[i-1])
            {
                i++;
                continue;
            }
            //if we get element of first array is smaller than second array element
            //then move to next element in first array as both arrays are sorted
            if(arr1[i]<arr2[j])
            {
                i++;
            }
            //if we get element of second array is smaller than first array element
            else if(arr1[i]>arr2[j])
            {
                j++;
            }
            //if we found both array element is same then store in the vector
            else{
                v.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        
        return v;
    }

};

//{ Driver Code Starts.
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        Solution ob;
        // Function calling 
        vector<int> v;
        v = ob.printIntersection(arr1, arr2, N, M); 
        
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";

        cout << endl;
    }
    
  return 0; 
} 

// } Driver Code Ends