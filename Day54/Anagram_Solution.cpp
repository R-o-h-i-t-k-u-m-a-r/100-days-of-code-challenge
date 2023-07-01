//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Using Character counting techinue storing all the frequencies of both strings
        int freq[256]={0};
        
        //if both string has different lenght then they can't be anagram
        if(a.length()!=b.length()){
            return false;
        }
        
        //In Freq array storing the sring a char as index and increasing thir frequecy 
        //and for string b char decreasing their frequency in Freq array
        for(int i=0;i<a.length();i++){
            freq[a[i]]++;
            freq[b[i]]--;
        }
        
        //if both string a and b would have same characters then frequency array will
        //have 0 in all the indexes if not then it means both string has not same chars
        for(int i=0;i<256;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends