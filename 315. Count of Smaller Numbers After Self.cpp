class Solution {
public:
    vector<int> count; // This will store the final count for each element

    void merge(vector<pair<int, int>>& arr, int low, int mid, int high) {
        int left = low, right = mid + 1;
        vector<pair<int, int>> temp;
        while (left <= mid && right <= high) {
            if (arr[left].first <= arr[right].first) {
                temp.push_back(arr[left]);
                count[arr[left].second] += (right - mid - 1);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            count[arr[left].second] += (right - mid - 1);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.resize(n, 0);  // Initialize the count vector to 0
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }
        mergeSort(arr, 0, n - 1);
        return count;
    }
};
