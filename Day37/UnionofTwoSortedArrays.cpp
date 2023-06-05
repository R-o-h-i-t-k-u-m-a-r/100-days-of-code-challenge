//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Solving this problem with the help of Merge algorithm
        
        //making two pointers for arr1 and arr2 
        int i=0,j=0;
        vector<int> v;
        //Iterate over the smallest one array
        while(i<n && j<m)
        {
            //if we found duplicate element in first array then left that element and 
            //move one index ahead
            if(i>0 && arr1[i]==arr1[i-1])
            {
                i++;
                continue;
            }
            //if we found duplicate element in second array then left that element and 
            //move one index ahead
            if(j>0 && arr2[j]==arr2[j-1])
            {
                j++;
                continue;
            }
            //if first element is smallest then second aray element then store it
            if(arr1[i]<arr2[j])
            {
                v.push_back(arr1[i]);
                i++;
            }
            //if second element is smaller than first array element then store it
            else if(arr1[i]>arr2[j])
            {
                v.push_back(arr2[j]);
                j++;
            }
            //if element in both arrays are same then include only one of array and 
            //move indexes ahead by one
            else{
                v.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        
        //check first array has remaining element to compare
        while(i<n)
        {
            if(i>0 && arr1[i]==arr1[i-1])
            {
               i++;
               continue;
            }
            v.push_back(arr1[i++]);
             
            
        }
        //check second array has remaining element to compare
        while(j<m)
        {
            if(j>0 && arr2[j]==arr2[j-1])
            {
                j++;
                continue;
            }
            v.push_back(arr2[j++]);
            
        }
        
        return v;
        //return vector with correct order of elements
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends