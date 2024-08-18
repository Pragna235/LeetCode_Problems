class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        int m = a.size();  // Number of rows/columns in the square matrix
        int n = m * m;  // Total number of elements in the matrix

        // Cast values to long long to avoid overflow
        long long SN = (n * (n + 1LL)) / 2;
        long long S2N = (n * (n + 1LL) * (2 * n + 1LL)) / 6;

        long long S = 0, S2 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                S += (long long)a[i][j];
                S2 += (long long)a[i][j] * (long long)a[i][j];
            }
        }

        long long val1 = S - SN;
        long long val2 = S2 - S2N;
        val2 = val2 / val1;

        long long X = (val2 + val1) / 2;
        long long Y = X - val1;

        return {(int)X, (int)Y};
    }
};
