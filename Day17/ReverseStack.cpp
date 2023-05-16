//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Reverse(stack<int> &st){
        //Base case of when stack has only one element
        if(st.size()==1)
        {
            return;
        }
        int data=st.top();
        st.pop();
        //hypothesis to reverse stack after decreasing size of stack by one 
        Reverse(st);
        //induction to reverse stack by inserting last data in the stack 
        insert(st,data);
    }
    void insert(stack<int>& st,int data)
    {
        if(st.size()==0)
        {
            st.push(data);
            return;
        }
        int temp=st.top();
        st.pop();
        insert(st,data);
        st.push(temp);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends