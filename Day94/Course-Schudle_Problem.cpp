//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        //Solving this problem with the concept of Topological sorting concept
        
        //Creating adjacency list from given course schedule
        vector<int> adj[N];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        int inDegree[N]={0};
	    
	    //Assuming here dependency task in terms of in-degree
	    for(int i=0;i<N;i++){
	        for(auto it:adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    //Inserting all the task into queue having dependency zero
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    //Implement topological sort 
	    vector<int> result;
	    while(q.empty()==false){
	        int task=q.front();
	        result.push_back(task);
	        q.pop();
	        
	        for(auto it:adj[task]){
	            inDegree[it]--;
	            if(inDegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    vector<int> err;
	    
	    if(result.size()==N) return result;
	    
	    return {};
	    //return result.size()==N?result:err;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends