class Solution {
    
    /*
        Time Complexity : O(n!)
        Space Complexity : O(n^2) + O(2*n) + O(n)
    */
    
private:
    vector<int> upperLeftDiagnal;
    vector<int> upperRightDiagnal;
    vector<int> upperCol;
    
    int res = 0;
    vector<string> board;
    
    void helper(int row, int size){
        if(row == size){
            res++;
            return;
        }
        
        for(int col=0; col<size; col++){
            if(upperCol[col]==0 and
               upperLeftDiagnal[row+col]==0 and
               upperRightDiagnal[(size-1)+col-row]==0
              ){
                board[row][col] = 'Q';
                upperCol[col] = upperLeftDiagnal[row+col] = upperRightDiagnal[(size-1)+col-row] = 1;
                helper(row+1, size);
                upperCol[col] = upperLeftDiagnal[row+col] = upperRightDiagnal[(size-1)+col-row] = 0;
                board[row][col] = '.';
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        upperLeftDiagnal.resize(2*n-1, 0);
        upperRightDiagnal.resize(2*n-1, 0);
        upperCol.resize(n, 0);
        
        board.resize(n);
        string s(n, '.');
        
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        //row, size
        helper(0, n);
        
        return res;
    }
};
