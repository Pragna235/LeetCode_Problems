class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi=nums[0];

        for(int i=1;i<nums.size();i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        while(mini>0 && maxi>0){
            if(mini>maxi) mini = mini%maxi;
            else maxi = maxi%mini;
        }
        if(mini==0) return maxi;
        return mini;
        
    }
};
