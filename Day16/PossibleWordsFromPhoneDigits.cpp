//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //storing all the possible keypad values
    vector<string> keypad = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Crating a string of vector for storing all combination
        vector<string> ans;
        keypadCombinations(a,"",N,ans,0);
    
        return ans;
        
    }
    
    void keypadCombinations(int a[],string op,int n,vector<string>& v,int temp)
    {
        //if there will be no keypad value left for combination
        if(temp==n)
        {
            v.push_back(op);
            return;
        }
        //Regtriving keypad value
        string str=keypad[a[temp]];
        
        for(int i=0;i<str.length();i++)
        {
            //Calling function for making combination of remaining keypad values after
            //adding one character 
            keypadCombinations(a,op+str[i],n,v,temp+1);
        }
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends