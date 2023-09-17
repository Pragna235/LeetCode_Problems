class Solution {
public:
    int countSetBits(int N){
        int count=0;
        while(N!=0){
            if((N&1)==1){
                count++;
            }
            N=N>>1;
        }
        return count;
    }
    
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0, n=nums.size();
        
        for (int i=0;i<n;i++){
            if(countSetBits(i) == k){
                sum+=nums[i];
            }
        }
        return sum;
        
    }
};
