class Solution {
public:
    int dayss(vector<int> &arr, int cap){
        int n = arr.size();
        int day=1,load=0;
        for(int i=0;i<n;i++){
            if(load+arr[i] > cap){
                day+=1;
                load=arr[i];
            }
            else{
                load+=arr[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            if(dayss(arr,mid) <= days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
