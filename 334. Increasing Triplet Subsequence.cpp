class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (int i : nums) {
            if (i <= m1) {
                m1 = i;
            } else if (i <= m2) {
                m2 = i;
            } else {
                return true;
            }
        }
        return false;
    }
};
