//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        //We are going to use character counting techique to store fequencies.
        
        //as we have only lower case character so we can store these char ascii upto 26
        int freq[26]={0};
        for(int i=0;i<str.length();i++){
            freq[str[i]-'a']++;
        }
        int ans=25;
        
        //Start traversing from right side so that we can take maximum frequiecies of 
        //left most character.
        for(int i=25;i>=0;i--){
            if(freq[i]>=freq[ans]){
                ans=i;
            }
        }
        
        //finally converting ascii to original char and return
        return char(ans+'a');
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends