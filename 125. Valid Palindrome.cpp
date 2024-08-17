#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> filtered;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
                filtered.push_back(s[i]);
            } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                filtered.push_back(s[i]);
            }
        }

        int start = 0;
        int end = filtered.size() - 1;

        while (start < end) {
            if (filtered[start] != filtered[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};
