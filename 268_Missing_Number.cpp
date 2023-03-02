class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        long long int sum=0;
        long long int n1=(n*(n+1))/2;
        for(int i=0;i<n;i++)
        {
           sum=sum+nums[i];
        }
        return n1-sum;

    }
};
