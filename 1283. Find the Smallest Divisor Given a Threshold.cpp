class Solution {
public:
    int sumOfD(vector<int> &arr, int div){
        long long ans=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            ans += ceil((double)arr[i] / (double)div);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n>threshold) return -1;

        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(sumOfD(nums,mid) <= threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
