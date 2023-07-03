//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
       //Here we are using lienear search Algo for finding the pattern
       
       //If both string has not same length then no need to check for ratation
       if(s1.length()!=s2.length()){
           return 0;
       }
       
       //if both string is same then all no need to check for ratation
       if(s1==s2)
       {
           return 1;
       }
       
       //If we marge s1 string it self then all the rotation of s1 can be obtained by 
       //merged string and by using this we can check s2 has valid rotation or not
       string rotatedString=s1+s1;
       
       //Traverse all the characters in new merged string
       for(int i=0;i<rotatedString.length();i++){
           int index=i,j=0;
           
           //if  char of merge string is matched with first char of s2 then only mathed 
           //for others s2 chars
           while(j<s2.length() && rotatedString[index]==s2[j]){
               j++;
               index++;
           }
           
           //if all the charcters of s2 string has been compared then it has been found
           if(j==s2.length()){
               return 1;
           }
       }
       
       return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends