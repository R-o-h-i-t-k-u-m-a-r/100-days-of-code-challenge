class Solution {
    public void solve(char[][] board) {

        //Creating visiting array of size board
        int n=board.length;
        int m=board[0].length;

        int visited[][]=new int[n][m];

        //Finding boundry O's at first and last row
        for(int j=0;j<m;j++){
            //for first row
            if(board[0][j]=='O' && visited[0][j]==0){
                DFS(0,j,n,m,board,visited);
            }
            
            //for last row
            if(board[n-1][j]=='O' && visited[n-1][j]==0){
                DFS(n-1,j,n,m,board,visited);
            }
        }

         //Finding boundry O's at first and last col
        for(int i=0;i<n;i++){
            
            //For first column
            if(board[i][0]=='O' && visited[i][0]==0){
                DFS(i,0,n,m,board,visited);
            }
            
            //For last column
            if(board[i][m-1]=='O' && visited[i][m-1]==0){
                DFS(i,m-1,n,m,board,visited);
            }
        }

         //Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
    }

    public void DFS(int row,int col,int n,int m,char[][] board,int[][] visited){

        visited[row][col]=1;

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 &&board[nrow][ncol]=='O'){
                DFS(nrow,ncol,n,m,board,visited);
            }
        }
    }
}