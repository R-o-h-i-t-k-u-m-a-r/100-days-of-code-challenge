//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStrings(int num){
        
        GenerateAllBinaryString(num,"");
    }
    void GenerateAllBinaryString(int n,string ans)
    {
        //Stop to calling further if n will be zero after reducing 
        if(n==0)
        {
            //displaying binary strings
            cout<<ans<<" ";
            return;
        }
        //Appending '0' to string  and reducing n by one
        GenerateAllBinaryString(n-1,ans+'0');
        if(ans.back()!='1')
        {
            //if last char is not '1' then appending '1' to string and reducing n by one
            GenerateAllBinaryString(n-1,ans+'1');
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends