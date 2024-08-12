class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array
    void computeLPSArray(string b, vector<int>& lps) {
        int m = b.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;

        while (i < m) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Function to perform KMP search
    bool KMPSearch(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<int> lps(m, 0);
        computeLPSArray(b, lps);

        int i = 0; // index for a[]
        int j = 0; // index for b[]
        while (i < n) {
            if (b[j] == a[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return true; // Found pattern b in string a
            } else if (i < n && b[j] != a[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string repeated_a = a;
        int count = 1;

        // Keep appending `a` until its length is at least `b.length()`
        while (repeated_a.length() < b.length()) {
            repeated_a += a;
            count++;
        }

        // Check if `b` is a substring of `repeated_a`
        if (KMPSearch(repeated_a, b)) {
            return count;
        }

        // Check if adding one more `a` makes `b` a substring
        repeated_a += a;
        count++;
        if (KMPSearch(repeated_a, b)) {
            return count;
        }

        return -1;
    }
};
