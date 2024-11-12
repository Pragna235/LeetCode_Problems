class Solution {
public:
    // Bottom-Up Approach: Iterative DP
    int solveBottomUp(vector<vector<char>>&matrix)
    {
         int n = matrix.size();  // Get number of rows
         int m = matrix[0].size();  // Get number of columns
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));  // DP array initialized to 0
         int maxi = 0;  // To store the largest square size

         // Traverse the matrix from bottom-right to top-left
         for(int i = n-1;i>=0;i--) {
            for(int j = m-1;j>=0;j--) {
                 // Calculate values from right, diagonal, and bottom
                 int right = dp[i][j+1];
                 int diagonal = dp[i+1][j+1];
                 int down = dp[i+1][j];

                 // If the current cell has a '1', calculate the square size
                 if(matrix[i][j]=='1') {
                    int ans = 1 + min(right, min(diagonal, down));
                    maxi = max(ans, maxi);  // Update the maximum square size
                    dp[i][j] = ans;  // Store the result in dp array
                 }
            }
         }
         // Return the area of the largest square
         return maxi * maxi;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Initialize required variables
        int i = 0;
        int j = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;

        // Bottom-Up DP solution
        int ans3 = solveBottomUp(matrix);

        return ans3;
    }
};
