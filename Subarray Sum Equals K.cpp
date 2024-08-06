class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        int sum=0;
        map<int,int> preSumMap;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }

            int rem = sum-k;

            if(preSumMap.find(rem)!=preSumMap.end()){
                count+=preSumMap[rem];
            }

            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum]=1;
            }
            else{
                preSumMap[sum]++;
            }
        }
        return count;
        
    }
};
