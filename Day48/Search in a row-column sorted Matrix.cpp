//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        //We are using Binary Search Techinque to find the element in the matrix 
        int i=0,j=m-1;
        
        //Ensuring our row and column index will be inside the matrix area while searching 
        //element
        while(i<=n-1 && j>=0)
        {
            //if we find element then return true
            if(matrix[i][j]==x)
            {
                return true;
            }
            //if our matrix element is less than given element then we need to 
            //move down side to search element
            else if(matrix[i][j]<x){
                i++;
            }
            //if our matrix element is less than given element then we need to 
            //move left side to search element
            else{
                j--;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends