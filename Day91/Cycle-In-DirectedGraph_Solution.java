//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for (int i = 0; i < V; i++)
                list.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
            }
            if (new Solution().isCyclic(V, list) == true)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/

class Solution {
    // Function to detect cycle in a directed graph.
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        //Creating visited aray and path array of size V initialize with 0
        int visited[]=new int[V];
        int path[]=new int[V];
        
        //Traversing all the graph component 
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                //Using DFS traversal if we found cycle in current node then we need to stop
                //for further cycle detection in graph 
                if(DFS(i,adj,visited,path)==true) return true;
            }
        }
        //if there is no cycle then return false
        return false;
    }
    
    public boolean DFS(int src,ArrayList<ArrayList<Integer>> adj,int visited[],int path[]){
        
        //marking visited array and path true for current node
        visited[src]=1;
        path[src]=1;
        
        //Traverse the all adjacency vertex of src node
        for(int i=0;i<adj.get(src).size();i++){
            int node=adj.get(src).get(i);
            
            //if node is node visited then check for its adjacency vertex
            if(visited[node]==0){
                
                //if we found cycle in current node then need to stop verifying further
                if(DFS(node,adj,visited,path)==true) return true;
                
            }
            //if node is visited before and also has same path then we have a cycle
            else if(path[node]==1) return true;
        }
        
        //If there is no adjacency vertex then we need to return by marking path clear
        path[src]=0;
        return false;
    }
}