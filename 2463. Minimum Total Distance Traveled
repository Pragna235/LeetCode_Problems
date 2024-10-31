class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort both robots and factories for optimal assignment
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int m = robot.size(), n = factory.size();
        // dp[i][j]: minimum total distance for robots[i:] using factories[j:]
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        
        // Base case: if no factories are available, distance is infinity
        for (int i = 0; i < m; i++) {
            dp[i][n] = LLONG_MAX;
        }
        
        // Process each factory from right to left
        for (int j = n - 1; j >= 0; j--) {
            // Track cumulative distance from current factory to robots
            long long prefix = 0;
            // Deque stores pairs of (robot index, minimum distance)
            deque<pair<int, long long>> qq;
            // Initialize with base case
            qq.push_back({m, 0});
            
            // Process each robot from right to left
            for (int i = m - 1; i >= 0; i--) {
                // Add distance from current robot to current factory
                prefix += abs(robot[i] - factory[j][0]);
                
                // Remove entries that exceed factory capacity
                while (!qq.empty() && qq.front().first > i + factory[j][1]) {
                    qq.pop_front();
                }
                
                // Maintain monotonic property of deque
                while (!qq.empty() && qq.back().second >= dp[i][j + 1] - prefix) {
                    qq.pop_back();
                }
                
                // Add current state to deque
                qq.push_back({i, dp[i][j + 1] - prefix});
                // Calculate minimum distance for current state
                dp[i][j] = qq.front().second + prefix;
            }
        }
        
        // Return minimum total distance starting from first robot and first factory
        return dp[0][0];
    }
};
