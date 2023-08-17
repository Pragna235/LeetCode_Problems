class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int result[n];
        int prefix[n];
        prefix[0]=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            result[i]=suffix*prefix[i];
            suffix*=nums[i];
        }
        
        vector<int> product;
        for(int i=0;i<n;i++){
            product.push_back(result[i]);
        }
        return product;
        
    }
};
