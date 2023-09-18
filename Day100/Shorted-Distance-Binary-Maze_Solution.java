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
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] grid = new int[n][m];

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < m; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }
            int[] source = new int[2];
            for (int i = 0; i < 2; i++) {
                int x = sc.nextInt();
                source[i] = x;
            }
            int[] dest = new int[2];
            for (int i = 0; i < 2; i++) {
                int x = sc.nextInt();
                dest[i] = x;
            }
            Solution ob = new Solution();
            int ans = ob.shortestPath(grid, source, dest);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class List{
    int dis;
    int row;
    int col;
    List(int dis,int row,int col){
        this.dis=dis;
        this.row=row;
        this.col=col;
    }
}

class Solution {

    int shortestPath(int[][] grid, int[] source, int[] destination) {

        //Solving this problem using Dijiktra's Algorithm but instead of using minHeap we will 
        //use queue ds here as distance will be growing constantly  by default and will be stored 
        //in ascending order by default 
        
        //If our source and destination is same then distance will be zero
        if(source[0]==destination[0] && source[1]==destination[1]) return 0;
        
        //Creating Queue ds to store distance of grid cell
        Queue<List> q=new LinkedList<>();
        
        //Creating distance array of equal size of grid initially initialize with large value
        int row=grid.length;
        int col=grid[0].length;
        int dist[][]=new int[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dist[i][j]=(int)(1e9);
            }
        }
        
        //Marking source node as 0 in distance array and inserting into queue also
        dist[source[0]][source[1]]=0;
        q.add(new List(0,source[0],source[1]));
        
        //Creating delta row and col to visit all the four direction of a grid cell
        int drow[] = {-1, 0, 1, 0}; 
        int dcol[] = {0, 1, 0, -1};
        
        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while(q.isEmpty()==false){
            int dis=q.peek().dis;
            int r=q.peek().row;
            int c=q.peek().col;
            q.remove();
            
            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && grid[nrow][ncol]==1
                && dis+1<dist[nrow][ncol]){
                    
                    dist[nrow][ncol]=1+dis;
                    
                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if(nrow==destination[0] && ncol==destination[1]) return 1+dis;
                    
                    q.add(new List(1+dis,nrow,ncol));
                }
            }
        }
        
        // If no path is found from source to destination.
        return -1;
    }
}
