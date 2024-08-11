class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        const int MAX_VAL = 1001; // Increase the limit to accommodate nums[i] <= 1000
        vector<vector<int>> dpPrev(MAX_VAL, vector<int>(MAX_VAL, 0));
        vector<vector<int>> dpCurr(MAX_VAL, vector<int>(MAX_VAL, 0));

        // Initialize dp for the first element
        for (int j = 0; j <= nums[0]; j++) {
            int k = nums[0] - j;
            if (k >= 0) {
                dpPrev[j][k] = 1;
            }
        }

        // Fill dp array
        for (int i = 1; i < n; i++) {
            vector<vector<int>> prefixSum(MAX_VAL, vector<int>(MAX_VAL + 1, 0));

            // Compute prefix sums for the previous row
            for (int j_prev = 0; j_prev < MAX_VAL; j_prev++) {
                for (int k_prev = 0; k_prev < MAX_VAL; k_prev++) {
                    prefixSum[j_prev][k_prev + 1] = (prefixSum[j_prev][k_prev + 1] + dpPrev[j_prev][k_prev]) % MOD;
                }
            }
            for (int j_prev = 0; j_prev < MAX_VAL; j_prev++) {
                for (int k_prev = 1; k_prev < MAX_VAL + 1; k_prev++) {
                    prefixSum[j_prev][k_prev] = (prefixSum[j_prev][k_prev] + prefixSum[j_prev][k_prev - 1]) % MOD;
                }
            }

            // Update dp for the current element
            for (int j = 0; j <= nums[i]; j++) {
                int k = nums[i] - j;
                if (k < 0) continue;

                for (int j_prev = 0; j_prev <= j; j_prev++) {
                    dpCurr[j][k] = (dpCurr[j][k] + prefixSum[j_prev][MAX_VAL] - prefixSum[j_prev][k]) % MOD;
                    if (dpCurr[j][k] < 0) dpCurr[j][k] += MOD;
                }
            }

            // Move current dp to previous dp for the next iteration
            dpPrev.swap(dpCurr);
            fill(dpCurr.begin(), dpCurr.end(), vector<int>(MAX_VAL, 0));
        }

        // Calculate result
        int result = 0;
        for (int j = 0; j < MAX_VAL; j++) {
            for (int k = 0; k < MAX_VAL; k++) {
                result = (result + dpPrev[j][k]) % MOD;
            }
        }

        return result;
    }
};
