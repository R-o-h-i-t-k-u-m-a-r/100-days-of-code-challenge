//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Solving this problem with Kahn's Algorithm Techninique
	    int inDegree[V]={0};
	    queue<int> q;
	    //Inserting in-degree of all the vertex of graph and also inserting all the vertex
	    //having 0 in-degree into queue
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            inDegree[it]+=1;
	        }
	    }
	    
	    //Inserting all the vertex having in-degree 0 into queue
	    for(int i=0;i<V;i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    //Implementing BFS Traversal to process all the adjacencies of corresponding vertex
	    vector<int> result;
	    while(q.empty()==false){
	        int node=q.front();
	        q.pop();
	        
	        //Traverse the adjacency of vertex
	        for(auto it:adj[node]){
	            if(inDegree[it]>0){
	                //Decreasing the vertex in-degree by one
	                inDegree[it]-=1;
	                //by decreassing the vertes degree if it became 0 then need to insert
	                //into queue
	                if(inDegree[it]==0){
	                    q.push(it);
	                }
	            }
	        }
	        //insert the current node for topo sort
	        result.push_back(node);
	    }
	    
	    
	    return result;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends