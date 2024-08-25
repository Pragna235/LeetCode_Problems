class Solution {
public:
    bool possible(vector<int> &arr, int day, int m, int k){
        int n = arr.size();
        int cnt=0,nOfB=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }
            else{
                nOfB += (cnt/k);
                cnt=0;
            }
        }
        nOfB += (cnt/k);
        return (nOfB>=m);
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        int n = arr.size();
        if(val>n) return -1;

        int low = *min_element(arr.begin(),arr.end());
        int high = *max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(arr,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};
