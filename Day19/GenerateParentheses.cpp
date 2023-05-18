//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> v;
        func(n*2,"",0,0,v,n);
        return v;
    }
    
    void func(int totalBrackets,string ans,int openBracket,int closeBracket, vector<string>& v,int n)
    {
        //writing base case if there will be no valid parenthesis remain
       if(totalBrackets==0)
       {
           v.push_back(ans);
           return;
       }
       //writing cases when only open parenthis will be add 
       if(ans.length()==0 || openBracket==closeBracket)
       {
           func(totalBrackets-1,ans+"(",openBracket+1,closeBracket,v,n);
       }
       //writing cases when only close parenthis will be add
       else if(openBracket>=n)
       {
           func(totalBrackets-1,ans+")",openBracket,closeBracket+1,v,n);
       }
       else{
           //add open parenthis in first calling
           func(totalBrackets-1,ans+"(",openBracket+1,closeBracket,v,n);
           //add close parenthis in second calling
           func(totalBrackets-1,ans+")",openBracket,closeBracket+1,v,n);
       }
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends