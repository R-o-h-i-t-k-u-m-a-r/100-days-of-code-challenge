//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool DFS(int node,vector<int> adj[],int visited[],int path[]){
        
        visited[node]=1;
        path[node]=1;
        
        //Traverse all the adjacency vertex of current node
        for(auto it:adj[node]){
            if(visited[it]==0){
                if(DFS(it,adj,visited,path)==true){
                    return true;
                }
            }
            else if(path[it]==1){
                return true;
            }
        }
        path[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int visited[V]={0};
        int path[V]={0};
        int isSafe[V]={0};
        vector<int> res;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                DFS(i,adj,visited,path);
            }
        }
        
        for(int i=0;i<V;i++){
            if(visited[i]==1 && path[i]==0){
                res.push_back(i);
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends