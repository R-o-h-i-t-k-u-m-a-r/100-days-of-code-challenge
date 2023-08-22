//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                // adj.get(v).add(u);
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.bfsOfGraph(V, adj);
            for (int i = 0; i < ans.size(); i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int v, ArrayList<ArrayList<Integer>> adj) {
        //Creating a visiting array to keep to track of visited vertex
        boolean visited[]=new boolean[v+1];
        
        //Creating a queue to process each vertex level order
        Queue<Integer> q=new LinkedList<Integer>();
        
        //Assuming source vertex is 0
        int source=0;
        
        //List for storing level order travrsal vertex
        ArrayList<Integer> list= new ArrayList<Integer>();
        
        //Mark source vertex visited initially and process in the queue for level order
        visited[source]=true;
        q.add(source);
        
        //Processing all the vertex of queue 
        while(q.isEmpty()==false){
            
            //if queue is not empty then take the source vertex and process all the edges
            int u=q.poll();
            list.add(u);
            
            //if source vertex has edge connetion to other vertex then push them into queue
            for(int data:adj.get(u)){
                if(visited[data]==false){
                    
                    //mark processing vertex as true so that we will not consider again to
                    //process
                    visited[data]=true;
                    q.add(data);
                }
            }
        }
        
        return list;
    }
}