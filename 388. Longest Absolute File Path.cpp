class Solution {
public:
    int lengthLongestPath(std::string input) {
        std::vector<int> stack = {0};  // Initialize with 0 to avoid empty stack issues
        int maxLen = 0;
        std::stringstream ss(input);
        std::string part;

        while (std::getline(ss, part, '\n')) {
            int level = part.find_last_of('\t') + 1;  // Level is determined by the number of tabs
            while (level + 1 < stack.size()) {
                stack.pop_back();  // Pop until the stack matches the current level
            }
            int length = stack.back() + part.length() - level + 1;  // Length includes '/'
            stack.push_back(length);

            if (part.find('.') != std::string::npos) {
                maxLen = std::max(maxLen, length - 1);  // Update max length if part contains '.'
            }
        }
        return maxLen;
    }
};
