class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi=0;
        int index=0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end());
            int cnt_ones = m - lowerBound(mat[i],m,1);
            if(cnt_ones>maxi){
                //cout<<"maxi = "<<maxi<<" cnt_ones = "<<cnt_ones<<" index = "<<index<<endl;
                maxi=cnt_ones;
                //cout<<"maxi = "<<maxi<<" cnt_ones = "<<cnt_ones<<" index = "<<index<<endl;
                index=i;
                //cout<<"maxi = "<<maxi<<" cnt_ones = "<<cnt_ones<<" index = "<<index<<endl;
                //cout<<endl;
            }
        }
        return {index,maxi};
    }
};
