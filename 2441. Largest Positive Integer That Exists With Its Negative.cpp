class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i] + nums[j] == 0){
                    result.push_back(nums[i]);
                }
            }
        }
        if(result.size() != 0){
            return *max_element(result.begin(),result.end());
        }
        
        return -1;
        
    }
};
