class Solution {
private:
    void dfs(int row, int col, int r[], int c[], vector<vector<int>> &visited, vector<vector<char>> &board){
        visited[row][col]=1;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+r[i];
            int ncol=col+c[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, r, c, visited, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));

        int r[]={1,0,-1,0};
        int c[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && visited[i][0]==0){
                dfs(i, 0, r, c, visited, board);
            }
            if(board[i][m-1]=='O' && visited[i][m-1]==0){
                dfs(i, m-1, r, c, visited, board);
            }
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && visited[0][j]==0){
                dfs(0, j, r, c, visited, board);
            }
            if(board[n-1][j]=='O' && visited[n-1][j]==0){
                dfs(n-1, j, r, c, visited, board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
