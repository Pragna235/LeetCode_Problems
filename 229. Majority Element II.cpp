class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0,c2=0,e1,e2;
        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=e2){
                c1=1;
                e1=nums[i];
            }
            else if(c2==0 && nums[i]!=e1){
                c2=1;
                e2=nums[i];
            }
            else if(nums[i]==e1)c1++;
            else if(nums[i]==e2)c2++;
            else{
                c1--;
                c2--;
            }
        }

        vector<int> res;
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1)c1++;
            if(nums[i]==e2)c2++;
        }
        int mini=int(n/3)+1;

        if(c1>=mini)res.push_back(e1);
        if(c2>=mini)res.push_back(e2);

        return res;
        
    }
};
