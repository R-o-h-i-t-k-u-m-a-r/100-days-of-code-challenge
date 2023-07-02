//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        
        // We are only going to count occurences of 1's in string and using that
        //to substring can be calulated by formulla.
        int count=0;
        
        for(int i=0;i<n;i++){
            if(a[i]=='1'){
                count++;
            }
        }
        
        return ((count*(count-1)/2));
    }

};

//{ Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}

// } Driver Code Ends