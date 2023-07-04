class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for ( i=0;i<n;i++){
            if(count(nums.begin(),nums.end(),nums[i]) == 1){
                break;
            }
        }
        return nums[i];
    }
};
