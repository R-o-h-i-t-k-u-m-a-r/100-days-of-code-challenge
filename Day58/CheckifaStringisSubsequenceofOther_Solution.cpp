//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B)
    {
        //Since order is matter in case of subsequence so pick large length string 
        //B to check wheter smaller length of string A's character is present in B or not
        
        //Store both string lengths
        int n=A.length();
        int m=B.length();
        
        //Taking j variable to traverse smaller string A
        int j=0;
        
        //Start traversing from string B which has more character than string A
        for(int i=0;i<m&&j<n;i++){
            
            //if we found String B character in String A then only increase j
            //so that we can move pointer ahead for compare next character of String B
            if(B[i]==A[j]){
                j++;
            }
        }
        
        //if we have traverse all the character of String A it means it is subsequence 
        //otherwise it is not
        return (j==n);
    }
};

//{ Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    string A, B; cin>>A>>B;
	    Solution ob;
	    bool ans = ob.isSubSequence(A, B);
	    if(ans == true)
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends