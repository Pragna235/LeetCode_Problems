class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;

        int i=0,j=0;
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        while(i<n && j<m){
            if(nums1[i] == nums2[j]){
                if(intersection.empty() || intersection.back()!=nums1[i]){
                intersection.push_back(nums1[i]);}
                i++;
                j++;
                
                //cout<<nums1[i]<<nums2[j]<<endl;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return intersection;
    }
};
