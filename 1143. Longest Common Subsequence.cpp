class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        std::vector<std::vector<int>> dpGrid(n + 1, std::vector<int>(m + 1, 0));

        for (int row = n - 1; row >= 0; row--) {
            for (int col = m - 1; col >= 0; col--) {
                if (text1[row] == text2[col]) {
                    dpGrid[row][col] = 1 + dpGrid[row + 1][col + 1];
                } else {
                    dpGrid[row][col] =
                        std::max(dpGrid[row + 1][col], dpGrid[row][col + 1]);
                }
            }
        }
        return dpGrid[0][0];
    }
};
