//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void DFS(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid,
    vector<pair<int,int>>& list,int row0,int col0){
        
        //Mark unvisited land as visited and insert their indexes into list by subtracting
        //base row and base column 
        visited[row][col]=1;
        list.push_back({row-row0,col-col0});
        
        int n=grid.size();
        int m=grid[0].size();
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                DFS(nrow,ncol,visited,grid,list,row0,col0);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        //To solve this problem we will use the concept of number of Island problem
        //approach to find the disticnt island we will create a list of indexes of each
        //island and store them into set 
        //here we will use base indes of each island which will be used to find index after
        //subtracting to island all indexes
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> hashTable;
        
        //Traversing the grid to find all the land available
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> list;
                    DFS(i,j,visited,grid,list,i,j);
                    hashTable.insert(list);
                }
            }
        }
        
        return hashTable.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends