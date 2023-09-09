//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool DFS(int node,vector<int> adj[],int visited[],int path[]){
        
        visited[node]=1;
        path[node]=1;
        
        for(auto it: adj[node]){
            //int src=adj[node][i];
            
            if(visited[it]==0){
                if(DFS(it,adj,visited,path)==true){
                    return true;
                }
            }
            
            else if(path[it]){
                return true;
            }
        }
        path[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        //Creating a visited array of size V
        int visited[V]={0};
        //vector<int> visited(V,0);
        
        //Creating a path visited array of size V
        int path[V]={0};
        //vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(DFS(i,adj,visited,path)==true){
                    return true;
                }
            }
        }
        
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends