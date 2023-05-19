//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    //Creating vector to store all the power set
		    vector<string> v;
		    
		    //Passing vector as a reference 
		    func(s,"",v);
		    
		    //Sorting vector strings after storing all the possible power sets
		    sort(v.begin(),v.end());
		    
		    return v;
		}
		
		void func(string s,string ans,vector<string>& v)
		{
		    //Return control to when there will be no string of char left
		    if(s.length()==0)
		    {
		        //keeping all the string rather than firt empty string
		        if(ans.length()>0)
		        {
		             v.push_back(ans);
		        }
		        return;
		    }
		    //Extracting first character of string
		    char ch=s[0];
		    //including first character to make subset and reducing string size by 1 char
		    func(s.substr(1),ans+ch,v);
		    //excluding first charachter and reducting string size by 1 char
		    func(s.substr(1),ans,v);
		  
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends