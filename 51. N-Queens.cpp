class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        if (n == 1) {
            results.push_back({"Q"});
            return results;
        }
        if (n == 2 || n == 3) {
            return results;
        }

        vector<int> solution(n, -1);
        solveNQueensRec(n, solution, 0, results);
        return results;
    }

private:
    void solveNQueensRec(int n, vector<int>& solution, int row,
                         vector<vector<string>>& results) {
        if (row == n) {
            vector<string> solutionStr = constructSolutionString(solution);
            results.push_back(solutionStr);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValidMove(row, col, solution)) {
                solution[row] = col;
                solveNQueensRec(n, solution, row + 1, results);
                solution[row] = -1; // Backtrack
            }
        }
    }

    bool isValidMove(int proposedRow, int proposedCol,
                     const vector<int>& solution) {
        for (int i = 0; i < proposedRow; i++) {
            int oldRow = i;
            int oldCol = solution[i];
            int diagonalOffset = proposedRow - oldRow;

            if (oldCol == proposedCol ||
                oldCol == proposedCol - diagonalOffset ||
                oldCol == proposedCol + diagonalOffset) {
                return false;
            }
        }
        return true;
    }

    vector<string> constructSolutionString(const vector<int>& solution) {
        vector<string> returnArr(solution.size(), string(solution.size(), '.'));
        for (int i = 0; i < solution.size(); i++) {
            returnArr[i][solution[i]] = 'Q';
        }
        return returnArr;
    }
};
