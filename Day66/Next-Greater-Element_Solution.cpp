//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        // Creating Stack for finding nextLargerElement of array
        stack<long long> s;
        
        //Vector container for storing nextLargerElement with the help of stack
        vector<long long> v(n);
        
        //Since we need to find first greater element from left to right side , so we 
        //are taking element from right end of array into stack , so that we will have
        //right most element at top to compare next element
        for(int i=n-1;i>=0;i--){
            
            //while element at top of stack is less than or equal to
            //current array element, we pop elements from the stack.
            while(!s.empty() && arr[i]>=s.top()){
                    s.pop();
                }
               
            //if stack becomes empty, we store -1 in the answer list 
            //else we store the top element of the stack.     
            if(s.empty()){
                v[i]=-1;
            }
            
            else if(arr[i]<s.top()){
                v[i]=s.top();
            }
            
            //pushing the current array element into the stack. 
            s.push(arr[i]);
        }
        
        //returning the list.
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends