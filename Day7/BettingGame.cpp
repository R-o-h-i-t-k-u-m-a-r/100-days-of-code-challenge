//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        int betBalance(string result)
        {
            // code here
            
            //Our Initial Balance and Initial Bet will be
            int balance=4, bet=1;
            for(int i=0;i<result.size();i++)
            {
                //if balance will be more than betting amount
                if(balance>=bet)
                {
                    //If user wins then
                    if(result[i]=='W')
                    {
                        balance=balance+bet;
                        bet=1;
                    }
                    //If user lose then
                    else if(result[i]=='L')
                    {
                        balance=balance-bet;
                        bet=2*bet;
                    }
                }
                else
                {
                    return -1;
                }
            }
            return balance;
        }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string result;
        cin>>result;
        
        Solution ob;
        cout<<ob.betBalance(result)<<endl;
    }
    return 0;
}
// } Driver Code Ends