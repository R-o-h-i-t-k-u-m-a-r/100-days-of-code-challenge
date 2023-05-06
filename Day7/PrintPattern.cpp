//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        // code here
        //Solving problem with the help of Recursion
        vector<int> v;
        int temp=N-5;
        bool flag=false;
        
        //Storing first element
        v.push_back(N);
        func(v,N,temp,flag);
        return v;
    }
    
    void func(vector<int>& v,int N, int temp, bool flag)
    {
        //Base case if if temp element is equal to inital element N
        if(temp==N)
        {
            v.push_back(temp);
            return;
        }
        else if(temp>0 && flag==false)
        {
            v.push_back(temp);
            func(v,N,temp-5,flag);
        }
        else if(temp>=0 && flag==true)
        {
            v.push_back(temp);
            func(v,N,temp+5,true);
        }
        else if(temp<=0)
        {
            v.push_back(temp);
            func(v,N,temp+5,true);
        }
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends