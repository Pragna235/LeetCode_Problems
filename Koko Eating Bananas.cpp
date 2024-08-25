class Solution {
public:
    int func(vector<int> &piles, int mid) {
        int ans = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            // Efficient ceiling division using integer arithmetic
            ans += (piles[i] + mid - 1) / mid;
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            int hours = func(piles, mid);
            if (hours > h) {
                low = mid + 1; // Mid is too small, need more speed
            } else {
                high = mid; // Mid might be enough, try a smaller value
            }
        }
        return low;
    }
};
