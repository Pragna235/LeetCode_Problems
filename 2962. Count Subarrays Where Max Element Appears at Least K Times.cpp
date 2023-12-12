class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector<int> store;
        long long ans=0,maxi = nums[0];
        for(auto n : nums){
            maxi = max(int(maxi),n);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                store.push_back(i+1);
            }
            if(store.size()>=k){
                ans+=store[store.size()-k];
            }
         
        }
           return ans;
        
    }
};
