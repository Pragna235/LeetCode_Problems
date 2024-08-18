class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count=0;
        long long xr = 0;
        map<int,int> mpp;
        mpp[xr]++;
        for(int i=0;i<n;i++){
            xr^=nums[i];
            int rem = xr^0;
            count+=mpp[rem];
            mpp[xr]++;
        }
        return count;
    }
};
