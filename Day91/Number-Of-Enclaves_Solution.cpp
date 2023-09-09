//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        //Solving this problem with the concept of Surrounded O's by X problem
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //Finding all four boundy of the grid having 1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1 && !visited[i][j]){
                        DFS(i,j,grid,visited);
                    }
                }
            }
        }
        
        //Finding boundry of the grid for first and last row
        // for(int j=0;j<m;j++){
        //     //for first row
        //     if(grid[0][j]==1 && visited[0][j]==0){
        //         DFS(0,j,grid,visited);
        //     }
            
        //     //for last row
        //     if(grid[n-1][j]==1 && visited[n-1][j]==0){
        //         DFS(n-1,j,grid,visited);
        //     }
        // }
        
        //Finding boundry of the grid for first and last column
        // for(int i=0;i<n;i++){
        //     //for first col
        //     if(grid[i][0]==1 && visited[i][0]==0){
        //         DFS(i,0,grid,visited);
        //     }
        //     //for last col
        //     if(grid[i][m-1]==1 && visited[i][m-1]==0){
        //         DFS(i,m-1,grid,visited);
        //     }
        // }
        
        //Find the number of land cells in grid for which we cannot walk off the
        //boundary of the grid in any number of moves.
        int landCount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    landCount++;
                }
            }
        }
        
        return landCount;
    }
    void DFS(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& visited){
        visited[row][col]=1;
        
        int n=grid.size();
        int m=grid[0].size();
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                DFS(nrow,ncol,grid,visited);
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends