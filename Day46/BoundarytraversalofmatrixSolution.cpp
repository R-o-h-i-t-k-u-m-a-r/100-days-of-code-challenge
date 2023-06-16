//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int R, int C) 
    {
        vector<int> v;
        //check if there is only one row
        if(R==1)
        {
            for(int i=0;i<C;i++)
            {
                v.push_back(matrix[0][i]);
            }
        }
        
        //Check if there is only one coloumn
        else if(C==1)
        {
            for(int i=0;i<R;i++)
            {
                v.push_back(matrix[i][0]);
            }
        }
        //Otherwise we will traverse four time to meet all the four side boundary
        else{
            for(int i=0;i<C;i++)
            {
                v.push_back(matrix[0][i]);
            }
            for(int i=1;i<R;i++)
            {
                v.push_back(matrix[i][C-1]);
            }
            for(int i=C-2;i>=0;i--)
            {
                v.push_back(matrix[R-1][i]);
            }
            for(int i=R-2;i>=1;i--)
            {
                v.push_back(matrix[i][0]);
            }
        }
        
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends