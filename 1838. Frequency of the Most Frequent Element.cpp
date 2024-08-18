#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;  // To store the sum of differences in the window
        int maxFreq = 1;      // Minimum possible frequency is 1
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];
            // If we need more than k operations to make all elements in the window equal to nums[right]
            while ((long long)(right - left + 1) * nums[right] - total > k) {
                total -= nums[left];
                left++;
            }
            // Update max frequency
            maxFreq = max(maxFreq, right - left + 1);
        }
        return maxFreq;
    }
};
