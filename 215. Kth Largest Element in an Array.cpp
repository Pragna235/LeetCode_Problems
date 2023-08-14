class Solution {
public:
int partition(vector<int> &arr, int left, int right){
    int pivot=arr[left];
    int l=left+1;
    int r = right;
    while(l<=r){
        if(arr[l]<pivot && arr[r] >pivot){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
        if(arr[l]>=pivot){
            l++;
        }
        if(arr[r]<=pivot){
            r--;
        }
    }
    swap(arr[left],arr[r]);
    return r;
}

int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1,kth;
        while(1){
            int idx=partition(nums,left,right);
            if(idx==k-1){
                kth=nums[idx];
                break;
            }
            if(idx<k-1){
                left=idx+1;
            }
            else{
                right=idx-1;
            }
        }
        return kth;
        
    }
};
