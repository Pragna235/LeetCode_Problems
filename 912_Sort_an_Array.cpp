class Solution {
public:
    void merge(int low, int mid, int high, vector<int> &nums) {
        if (low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        while (l <= mid)
            sorted[k++] = nums[l++];
        while (r <= high)
            sorted[k++] = nums[r++];
        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start < end){
            int mid = start + (end - start) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(start, mid, end, nums);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
