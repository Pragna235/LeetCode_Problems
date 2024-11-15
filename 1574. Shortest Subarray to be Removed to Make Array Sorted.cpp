class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size();
        
        // Find longest non-decreasing prefix
        int left= 0;
        for (; left+1 < n && arr[left] <= arr[left+1]; left++); 
        
        // array is already non-decreasing
        if (left== n-1) return 0;
        
        // Find longest non-decreasing suffix
        int right = n-1;
        for (; right>left && arr[right-1] <= arr[right]; right--);     
        
        // to remove as the smaller of removing all from either end
        int remove = min(n-left-1, right);
        
        // Try to merge left and right parts
        for (int i = 0, j = right; i <= left && j < n; ) {
            if (arr[i] <= arr[j]) {
                //  remove elements  with index in (i, j)
                remove = min(remove, j-i-1);
                i++;
            } 
            else j++;  
        }
        
        return remove;
    }
};
