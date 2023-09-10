//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            String st[] = read.readLine().trim().split("\\s+");
            int edg = Integer.parseInt(st[0]);
            int nov = Integer.parseInt(st[1]);

            for (int i = 0; i < nov; i++)
                list.add(i, new ArrayList<Integer>());

            int p = 0;
            for (int i = 1; i <= edg; i++) {
                String s[] = read.readLine().trim().split("\\s+");
                int u = Integer.parseInt(s[0]);
                int v = Integer.parseInt(s[1]);
                list.get(u).add(v);
            }

            int[] res = new Solution().topoSort(nov, list);

            if (check(list, nov, res) == true)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
    static boolean check(ArrayList<ArrayList<Integer>> list, int V, int[] res) {
        
        if(V!=res.length)
        return false;
        
        int[] map = new int[V];
        for (int i = 0; i < V; i++) {
            map[res[i]] = i;
        }
        for (int i = 0; i < V; i++) {
            for (int v : list.get(i)) {
                if (map[i] > map[v]) return false;
            }
        }
        return true;
    }
}

// } Driver Code Ends


/*Complete the function below*/


class Solution
{
    //Function to return list containing vertices in Topological order. 
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        //Solving this problem with DFS traversal by storing vertex in stack corresponding
        int visited[]=new int[V];
        Stack<Integer> st = new Stack<Integer>();
        int res[]=new int[V];
        
        //Traversing all the graph components using DFS traversal technique
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                DFS(i,adj,visited,st);
            }
        }
        
        //Inserting all the stack node into result array
        int i=0;
        while(st.isEmpty()==false){
            res[i++]=st.peek();
            st.pop();
        }
        
        return res;
    }
    
    static void DFS(int node,ArrayList<ArrayList<Integer>> adj,int visited[]
    ,Stack<Integer> st){
        //Mark node as visited 
        visited[node]=1;
        
        //Traversing all the non visiting adjacency vertex of current node
        for(int i=0;i<adj.get(node).size();i++){
            int it=adj.get(node).get(i);
            
            if(visited[it]==0){
                DFS(it,adj,visited,st);
            }
        }
        //when there is not adjacency vertex remain then push current node into stack
        st.push(node);
    }
}
