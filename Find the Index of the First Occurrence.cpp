class Solution {
public:

    void computeLPSArray(string &pattern, int m, vector<int> &lps){
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<m){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int strStr(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        int i = 0, j = 0;
        vector<int> lps(m, 0);
        vector<int> result;  // Initialize an empty result vector
        computeLPSArray(pattern, m, lps);

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                result.push_back(i - j);  // Store the index where pattern is found
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        // If no occurrence found, return -1, else return the first occurrence
        return result.empty() ? -1 : result[0];
    }
};
