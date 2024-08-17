class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi=0,sum=0;
        
        //mpp[0]=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==0) 
            {
                nums[i]=-1;
            }
        }
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            //cout<<"sum = "<<sum<<endl;
            if(sum==0){
                maxi = i+1;
                //cout<<"if i = "<<i<<endl;
                //cout<<"if maxi = "<<maxi<<endl;
            }
            else{
                if(mpp.find(sum)!=mpp.end()){
                    maxi = max(maxi,i-mpp[sum]);
                    //cout<<"else maxi = "<<maxi<<endl;
                }
                else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
};
