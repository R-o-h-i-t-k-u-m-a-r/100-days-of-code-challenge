//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        //Creating a Stack container to check parenthesis
        stack<char> s;
        
        //Creating a hash map to stroe all the possible parenthesis valid order pairs
        map<char,char> m;
        m['}']='{';
        m[')']='(';
        m[']']='[';
        
        //if we have odd number of parenthesis then that can not be balanced
        if(x.length()%2){
            return false;
        }
        
        //pushing first character at empty stack
        s.push(x[0]);
        
        //Traverse all the remainig characters of string 
        for(int i=1;i<x.length();i++){
            
            //if stack is not empty and our top of stack char valid pair is 
            //same as incoming char pop stack
            if(!s.empty() && s.top()==m[x[i]]){
                s.pop();
            }
            
            //otherwise push into stack
            else{
                s.push(x[i]);
            }
        }
        
        //return whether stack is empty or not
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends