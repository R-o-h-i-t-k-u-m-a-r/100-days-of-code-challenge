//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code 
        vector<vector<int>> v;
        
        //Assuming buy and sell at first element of array
        int buy=0;
        int sell=0;
        for(int i=0;i<n-1;i++)
        {
            //if next element would be greater then previous 
            if(A[i+1]>A[i]){
                sell++;
            } else{
                //if sell is greater then buy then store the profit range
                if(sell>buy){
                    vector<int> v1;
                    v1.push_back(buy);
                    v1.push_back(sell);
                    v.push_back(v1);
                    
                }
                //Reset the value of buy and sell after storing profit range
                buy=i+1;
                sell=i+1;
            }
        }
        //fot last index of array
        if(sell>buy){
                    vector<int> v1;
                    v1.push_back(buy);
                    v1.push_back(sell);
                    v.push_back(v1);
                    
                }
                
        return v;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends