//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


void printVector(const vector<int>& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

// } Driver Code Ends
class Solution{
  public:
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    { 
        //Creating a vector to merge sorted arrays A and B
        vector<int> temp;
        
        //Merging two sorted arrays A and B in a vector first
        mergeTwo(A,B,temp);
        
        //Creating another vector to merge sorted array C and previous merged A and B
        vector<int> ans;
        
        //Now again merging last remaing array C with previous two merged arrays
        mergeTwo(C,temp,ans);
        
        //Finally return merge of all three sorted arrays
        return ans;
    } 
    
    //Writing Merge function to merge two sorted arrays
    void mergeTwo(vector<int>& a,vector<int>& b,vector<int>& temp)
    {
    int i=0,j=0;
    //Iterating upto the smallest one lenth array
    while(i<a.size() && j<b.size())
    {
        //if first one array element is smaller than second one array element 
        if(a[i]<b[j])
        {
            //then store the element
            temp.push_back(a[i]);
            i++;
        }
        //if second one array element is smallert than first one array element
        else if(a[i]>b[j])
        {
            //then store the element
            temp.push_back(b[j]);
            j++;
        }
        //if both have same element then store any one of array element
        else{
            temp.push_back(b[j]);
            j++;
        }
    }
    //check if first array has remains element to compare
    while(i<a.size())
    {
        temp.push_back(a[i]);
        i++;
    }
    //check if second array has remains element to compare
    while(j<b.size())
    {
        temp.push_back(b[j]);
        j++;
    }
    }
};

//{ Driver Code Starts.

int main() 
{ 


    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    vector<int> A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }

    Solution obj;
    vector<int>ans = obj.mergeThree(A, B, C);
    for(auto i: ans)cout << i << " ";
    cout << "\n";
    // obj.printVector(mergeThree(A, B, C)); 
    
    }
   
    return 0; 
} 

// } Driver Code Ends