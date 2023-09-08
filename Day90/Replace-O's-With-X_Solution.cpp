//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        //Creating visited matrix 
        vector<vector<int>> visited(n,vector<int>(m,0));
        

        //Finding O's at Row boundries
        for(int j=0;j<m;j++){
            if(visited[0][j]==0 && mat[0][j]=='O'){
                DFS(0,j,mat,visited);
            }
            if(visited[n-1][j]==0 && mat[n-1][j]=='O'){
                DFS(n-1,j,mat,visited);
            }
        }
        
        //Finding O's at Column boundries
        for(int i=0;i<n;i++){
            if(visited[i][m-1]==0 && mat[i][m-1]=='O'){
                DFS(i,m-1,mat,visited);
            }
            if(visited[i][0]==0 && mat[i][0]=='O'){
                DFS(i,0,mat,visited);
            }
        }
        
        //Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return mat;
    }
    
    void DFS(int row,int col,vector<vector<char>> mat,vector<vector<int>>& visited){
        int n=mat.size();
        int m=mat[0].size();
        
        visited[row][col]=1;
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        //Creating for Stack for DFS call 
        stack<pair<int, int>> s;
        s.push({row, col});
        
        //Impleting DFS using stack
        while (!s.empty()) {
            pair<int, int> curr = s.top();
            s.pop();
        
            for (int i = 0; i < 4; i++) {
                int nrow = curr.first + drow[i];
                int ncol = curr.second + dcol[i];
            
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && visited[nrow][ncol] == 0 && mat[nrow][ncol] == 'O') {
                    visited[nrow][ncol] = 1;
                    s.push({nrow, ncol});
                    
                }
                
            }
            
        }
        
        // for(int i=0;i<4;i++){
        //     int nrow=row+drow[i];
        //     int ncol=col+dcol[i];
            
        //     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 
        //     && mat[nrow][ncol]=='O'
        //     ){
        //         DFS(nrow,ncol,mat,visited);
        //     }
        // }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends