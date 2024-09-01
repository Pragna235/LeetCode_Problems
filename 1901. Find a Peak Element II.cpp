class Solution {
public:
    int maxIndex(vector<vector<int>> &mat, int n, int m, int col){
        int maxi=-1,ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int rowIndex = maxIndex(mat,n,m,mid);
            int left = mid-1>=0 ? mat[rowIndex][mid-1] : -1;
            int right = mid+1 < m ? mat[rowIndex][mid+1] : -1;

            if(mat[rowIndex][mid] > left && mat[rowIndex][mid] > right){
                return {rowIndex, mid};
            }
            else if(mat[rowIndex][mid] < left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};
