//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    //Solving this problem with the concept of Topological sorting algorithm
	    
	    //Converting prerequisites into adjacency list
	    vector<int> adj[N];
	    for(auto it:prerequisites){
	        //int task1=prerequisites[i].first;
	        //int task2=prerequisites[i].second;
	        
	        adj[it.first].push_back(it.second);
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
	    int cnt=0;
	    while(q.empty()==false){
	        int task=q.front();
	        cnt++;
	        q.pop();
	        
	        for(auto it:adj[task]){
	            inDegree[it]--;
	            if(inDegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return cnt==N?true:false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends