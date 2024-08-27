class Solution {
public:
    int noOfSubsets(vector<int> &nums, int subsets){
        long long sum=0;
        int sub=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] + sum <= subsets){
                sum+=nums[i];
            }
            else{
                sub++;
                sum = nums[i];
            }
        }
        return sub;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int sub = noOfSubsets(nums,mid);
            if(sub>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
