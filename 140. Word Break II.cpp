class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        // Create a Set of words from the array so that the
        // lookup cost in the Set becomes O(1)
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // Initialize the lookup table
        vector<vector<string>> dp(n + 1);

        // Set the first element to an empty string
        dp[0].push_back("");

        for (int i = 1; i <= n; i++) {
            vector<string> temp;
            for (int j = 0; j < i; j++) {
                string suffix = s.substr(j, i - j);
                // Checking if the substring from j to i is
                // present in the wordSet
                if (wordSet.find(suffix) != wordSet.end()) {
                    // Retrieve the valid sentences from the
                    // previously computed subproblem
                    for (const string& substring : dp[j]) {
                        // Merge the suffix with the already
                        // calculated results, excluding the leading
                        // space
                        temp.push_back(substring +
                                       (substring.empty() ? "" : " ") + suffix);
                    }
                }
            }
            dp[i] = temp;
        }

        // Return the last element of dp array It contains all
        // the sentences formed from the complete string s.
        return dp[n];
    }
};
