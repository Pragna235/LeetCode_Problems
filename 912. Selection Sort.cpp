class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int mini = i;
            for(int j=i;j<n;j++){
                if(nums[j]<nums[mini]){
                    mini=j;
                }
            }
            swap(nums[i],nums[mini]);
        }
        return nums;
    }
};
