#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(const std::vector<int>& nums) {
        std::vector<int> lis;

        for (int num : nums) {
            auto it = std::lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }

        return lis.size();
    }
};
