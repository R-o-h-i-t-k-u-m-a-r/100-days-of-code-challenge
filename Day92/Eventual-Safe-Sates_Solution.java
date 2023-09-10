//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();

            List<List<Integer>> adj = new ArrayList<>();

            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();

                adj.get(u).add(v);
            }

            Solution obj = new Solution();
            List<Integer> safeNodes = obj.eventualSafeNodes(V, adj);
            for (int i : safeNodes) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {
        //We are gonna solve this problem this the concept of cycle in directed graph concept
        //in which node that is not forming cycle neither leading to cycle will be assume as 
        //safe node
        
        int visited[] = new int[V];
        int path[] = new int[V];
        List<Integer> safeNode= new ArrayList<>();
        
        //Traversing all the graph components
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                DFS(i,adj,visited,path);
            }
        }
        //Selecting all the vertex from path which are not a part of cycle in graph
        //that will be our safe node
        for(int i=0;i<V;i++){
            if(path[i]==0){
                safeNode.add(i);
            }
        }
        
        return safeNode;
    }
    
    boolean DFS(int node,List<List<Integer>> adj, int visited[],int path[]){
        //marking node as visited both array 
        visited[node]=1;
        path[node]=1;
        
        //Traversing all the adjacency vertex of current node
        for(int i=0;i<adj.get(node).size();i++){
            int curr=adj.get(node).get(i);
            
            //if current node is not visited before then check it cause cycle or not 
            if(visited[curr]==0){
                if(DFS(curr,adj,visited,path)==true){
                    return true;
                }
            }
            //if current node is visited before and also visited in same path then it is forming 
            //cycle 
            else if(path[curr]==1){
                return true;
            }
        }
        //if node is not forming cycle then removing the visited path
        path[node]=0;
        return false;
    }
}
