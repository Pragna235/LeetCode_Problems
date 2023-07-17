class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                nums[i]=0;
                
            }
            else{
                count++;
            }
        }
        sort(nums.begin(),nums.end(),greater<int>());
        return count;
        
    }
};
