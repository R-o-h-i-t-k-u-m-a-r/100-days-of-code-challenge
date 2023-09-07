//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int[][] grid = new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            int ans = obj.orangesRotting(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


class Solution
{
    //Function to find minimum time required to rot all oranges. 
    public int orangesRotting(int[][] grid)
    {
        //Crating Queue for BFS Traversal of girid which will store index of roten fruit and 
        //time unit of each traversal
        Queue<ArrayList<Integer>> q = new LinkedList<>();
        
        //Getting row and col of grid to create visited array
        int row = grid.length;
        int col = grid[0].length;
        int[][] visited = new int[row][col];
        int timeUnit=0;
       
       //Inserting values into visited array from grid
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               visited[i][j]=grid[i][j];
               //if we found roten fruit then store its index into queue with 0 timeunit
               if(grid[i][j]==2){
                   ArrayList<Integer> data= new ArrayList<>();
                   data.add(i);
                   data.add(j);
                   data.add(0);
                   q.add(data);
               }
           }
       }
       
       //Process the rotten fruit in the queue
       while(q.isEmpty()==false){
           ArrayList<Integer> data= q.poll();
           int first=data.get(0);
           int second=data.get(1);
           int third=data.get(2);
            //timeUnit = third+1;
           //Now check for top fruit
           if(0<first){
               //if there is fresh fruit found at top then make fruit rot and store index
               if(visited[first-1][second]==1){
                   visited[first-1][second]=2;
                   ArrayList<Integer> item = new ArrayList<>();
                   item.add(first-1);
                   item.add(second);
                   item.add(third+1);
                   q.add(item);
                   timeUnit = third+1;
               }
           }
           
           //Now check for bottom fruit
           if(first<row-1){
               //it there si fresh fruit found at botom the make fruit rot and store index
               if(visited[first+1][second]==1){
                   visited[first+1][second]=2;
                   ArrayList<Integer> item = new ArrayList<>();
                   item.add(first+1);
                   item.add(second);
                   item.add(third+1);
                   q.add(item);
                   timeUnit = third+1;
               }
           }
           //Now check for left fruit
           if(0<second){
               //if there is fresh fruit found at left them make fruit rot and store index
               if(visited[first][second-1]==1){
                   visited[first][second-1]=2;
                   ArrayList<Integer> item = new ArrayList<>();
                   item.add(first);
                   item.add(second-1);
                   item.add(third+1);
                   q.add(item);
                   timeUnit = third+1;
               }
           }
           //Now check for right fruit
           if(second<col-1){
               //if there is fresh fruit found at right then make fruit rot and store index
               if(visited[first][second+1]==1){
                   visited[first][second+1]=2;
                   ArrayList<Integer> item = new ArrayList<>();
                   item.add(first);
                   item.add(second+1);
                   item.add(third+1);
                   q.add(item);
                   timeUnit = third+1;
               }
           }
       }
       
       //Traverse visited array if there is any fresh fruit found or not 
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(visited[i][j]==1)
               {
                   return -1;
               }
           }
       }
       
       return timeUnit;
    }
}