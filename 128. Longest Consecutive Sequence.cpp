class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        unordered_set<int> s;
        int count=0, longest=1, lastSmaller=INT_MIN;

        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }

        for(auto it: s){
            if(s.find(it-1) == s.end()){
                count=1;
                lastSmaller=it;
                while(s.find(lastSmaller+1) != s.end()){
                    count++;
                    lastSmaller++;
                }
            }
            longest = max(longest,count);
        }
        return longest;
    }
};
