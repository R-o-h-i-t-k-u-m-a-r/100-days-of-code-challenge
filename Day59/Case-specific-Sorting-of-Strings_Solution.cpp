//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        //Solving this problem by sorting lower case char's and upper case char's
        //separetly and use that sorted char's to merge  according to requirments
        string lower;
        string upper;
        string res;
        
        //Inserting char's in lowera and upper case string indivisually from original 
        //string 
        for(int i=0;i<n;i++){
            if(islower(str[i])){
                lower.push_back(str[i]);
            }
            else{
                upper.push_back(str[i]);
            }
        }
        
        //Sorting both lower case string and upper case string 
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        
        //Now as we have both lower and upper case string is sorted so while traversing 
        //original string if we find lower case then will take char from lower string 
        //and when we find upper case char then will take char from upper string.
        for(int i=0;i<n;i++){
            if(islower(str[i])){
                res.push_back(lower[0]);
                lower.erase(lower.begin());
            }
            else{
                res.push_back(upper[0]);
                upper.erase(upper.begin());
            }
        }
        
        return res;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends