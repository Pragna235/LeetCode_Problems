class Solution {
public:

    void computeLPSArray(string s, vector<int>& lps){
        int m = s.size();
        int len = 0;
        
        lps[0] = 0;
        int i = 1;

        while(i < m){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string longestPrefix(string s) {
        int m = s.size();
        vector<int> lps(m, 0);
        computeLPSArray(s, lps);

        int maxi = lps[m - 1]; // Length of the longest prefix which is also a suffix

        return s.substr(0, maxi); // Return the longest prefix
    }
};
