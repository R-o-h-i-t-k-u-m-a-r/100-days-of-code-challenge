//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        //Solving this problem with the help of Topological sorting technique
        
        //Reversing the adjanceny list and also storing in-degree of each vertex
        vector<int> revAdj[V];
        int inDegree[V]={0};
        for(int i=0;i<V;i++){
            
            //i-->it
            //it-->i
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        //Inserting all the vertex into queue having in-degree 0
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        //Implementing Topological sort algorithm
        vector<int> safeNode;
        while(q.empty()==false){
            int node=q.front();
            q.pop();
            safeNode.push_back(node);
            
            for(auto it:revAdj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        sort(safeNode.begin(),safeNode.end());
        return safeNode;
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